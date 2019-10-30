<?php
        $conn = mysqli_connect(                         //mysql 연결
          'localhost',
          'mhj',
          '111111',
          'proj_manager');

        mysqli_set_charset($conn, 'utf8');
        //mysql 인코딩 형식 통일

        //TEM 테이블에서 가장 최근의 값을 불러옴
        $sql = "SELECT Tem FROM TEM ORDER BY Time DESC limit 1;";

        $result = mysqli_query($conn, $sql);

        //jspn형식으로 데이터를 전송
        $row = mysqli_fetch_assoc($result);
        echo $row['Tem'];


?>
