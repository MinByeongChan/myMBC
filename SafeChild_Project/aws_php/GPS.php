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

        //RaspPi에서 보낸 각각 위도, 경도 값을 의미
        $latitude = $_POST["lat"];
        $longitude = $_POST["lon"];

        //쿼리 등록
        $gps_sql = "SELECT ID FROM GPS;";
        $result_gps = mysqli_query($db, $gps_sql);
        
        //GPS테이블 내 등록된 레코드 개수
        $total_rows = mysqli_num_rows($result_gps);

        //전체 ID개수가 500개 이상이면 0으로 초기화
        if($total_rows >= 500) {
                $gps_sql = "delete from GPS;";
                $result_gps = mysqli_query($db, $gps_sql);
                $total_rows = 0;
        }

        echo $total_rows;
        
        $gps_sql = "INSERT INTO GPS(Latitude, Longitude, ID) VALUES('$latitude', '$longitude', '$total_rows');";

        //sql문을 query함수를 사용해 실행시킴
        //db에 데이터가 저장시킴
        $result_gps = mysqli_query($db, $gps_sql);
        if($result_gps == false){
                echo mysqli_error($db);
        }

        mysqli_close($db);
?>