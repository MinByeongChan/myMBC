
<?php
    //post방식으로 데이터를 받음
    $Kindergarten = $_POST["Kindergarten"];
    $BusStation = $_POST["BusStation"];
    $userName = $_POST["userName"];
    $userID = $_POST["userID"];
    $userPasswordtemp = $_POST["userPassword"];
    $userPhone = $_POST["userPhone"];
    $userEmail = $_POST["userEmail"];
    $userGender = $_POST["userGender"];
    $userCode = $_POST["userCode"];
    $userState = $_POST["userState"];
    $token = $_POST["Token"];
    
    //MySQL에 연결
    $con = mysqli_connect('localhost', 'mhj', '111111', 'proj_manager');
    
    //MySQL 연결 실패하면
    if (!$con)
    {
      echo "MySQL 접속 에러 : ";
      echo mysqli_connect_error();
      exit();
    }
 
    //post방식으로 데이터를 받음
    $userPassword = base64_encode(hash('sha512', $userPasswordtemp, true));

    //MySQL 글자 형식 통일
    mysqli_set_charset($con, 'utf8');

    $test = "INSERT INTO USER (Name,ID,PW,Email,Number,Code,State,token,Kinder,Station)  
        VALUES ('$userName', '$userID', '$userPassword', '$userEmail', '$userPhone', '$userCode', '$userState', '$token', '$Kindergarten', '$BusStation')";

    mysqli_query($con,$test);
    mysqli_close($con);


    //배열 선언후
    $response = array();
    $response["success"] = true;  //success라는 인덱스에 true값을 넣어줌
    
    echo json_encode($response);  //JSON형식으로 출력


