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

        //raspberryPi에서 전송하는 데이터를 Mysql데이터베이스에 올림
        
        //차량 아이의 인원수
        $cnt=$_POST['count'];
        
        //ID는 라즈베리파이 각 고유 번호
        //차량 번호를 의미
        $ID=$_POST['ID'];
        
//      $sql = "UPDATE CNT SET Cnt = $cnt;";
        $sql = "INSERT INTO CNT(Cnt,ID) VALUES($cnt,$ID);";
        echo $cnt;

        echo "#####";
//        $sql = "INSERT INTO COUNT(Cnt) VALUES($count);";
        $result_t=mysqli_query($db, $sql);
        if($result_t == false){
                echo mysqli_error($db);
        }
        echo "##########";
        $sql_t="SELECT * FROM CNT;";
        while($row_t = mysqli_fetch_assoc($result_t)){
                echo $row_t['Cnt'];  echo "\n";

        }
        mysqli_close($db);
?>
