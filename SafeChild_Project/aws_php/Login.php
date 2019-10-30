<?php

    $con = mysqli_connect('localhost', 'mhj', '111111', 'proj_manager');

    mysqli_set_charset($con, 'utf8');              //mysql 인코딩 형식 통일


    $userID = $_POST["userID"];
    $userPasswordtemp = $_POST["userPassword"];

    //패스워드 암호화
    $userPassword = base64_encode(hash('sha512', $userPasswordtemp, true));

    //받은 데이터가 테이블에 있는지 검사
    $statement = mysqli_prepare($con, "SELECT State FROM USER WHERE ID = ? AND PW = ?");

    mysqli_stmt_bind_param($statement, "ss", $userID, $userPassword);
    mysqli_stmt_execute($statement);
    mysqli_stmt_store_result($statement);

    $sql = "select * from USER where ID = '$userID';";
    $result = mysqli_query($con, $sql);

    $temp = mysqli_fetch_array($result);
    $result1 = $temp[4];

    $sql_Parent = "select * from USER where ID = 'Parent';";
    $result_Parent = mysqli_query($con, $sql_Parent);
    $temp_Parent = mysqli_fetch_array($result_Parent);
    $result1_Parent = $temp_Parent[4];

    $sql_Admin = "select * from USER where ID = 'Admin';";
    $result_Admin = mysqli_query($con, $sql_Admin);
    $temp_Admin = mysqli_fetch_array($result_Admin);
    $result1_Admin = $temp_Admin[4];

    mysqli_stmt_bind_result($statemenet, $userID, $userPassword, $userKinder);

    $response = array();
    $response["success"] = false;

    //로그인시 학부모 또는 유치원 관계자를 구분해서 로그인
    if($result1 == $result1_Parent){
        $response["State"] = true;
    }

    else{
        $response["State"] = false;
    }
     
    while(mysqli_stmt_fetch($statement)){
        $response["success"] = true;
    }
    


    echo json_encode($response);
    echo $result1;

     mysqli_close($con);
?>


