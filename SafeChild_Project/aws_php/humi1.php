<?php
        $conn = mysqli_connect(                         //mysql 연결
          'localhost',
          'mhj',
          '111111',
          'proj_manager');

        mysqli_set_charset($conn, 'utf8');
        //mysql 인코딩 형식 통일

        //tem1코드와 유사
        $sql = "SELECT Humi FROM TEM ORDER BY Time DESC limit 1;";

        $result = mysqli_query($conn, $sql);

        $row = mysqli_fetch_assoc($result);
        echo $row['Humi'];


?>