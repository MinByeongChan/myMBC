<?php
        $db = mysqli_connect(                         //mysql 연결
          'localhost',
          'mhj',
          '111111',
          'proj_manager');

        if($db){
            echo "connect : 성공<br>";
        }
        else{
            echo "disconnect : 실패<br>";
        }

        mysqli_set_charset($db, 'utf8');              //mysql 인코딩 형식 통일

        $temper=$_POST['temper'];
        $humi=$_POST['hum'];
        $ID=$_POST['ID'];
        
        //RaspPi에서 보낸 온도, 습도, 라즈베리파이 ID값을 받고 데이터베이스에 등록

        $sql = "INSERT INTO TEM(Tem,Humi,ID) VALUES($temper,$humi,$ID);";
        $result_t=mysqli_query($db, $sql);
        if($result_t == false){
                echo mysqli_error($db);
        }

        mysqli_close($db);
?>
