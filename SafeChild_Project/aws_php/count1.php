
<?php
        $conn = mysqli_connect(                         //mysql 연결
          'localhost',
          'mhj',
          '111111',
          'proj_manager');

        mysqli_set_charset($conn, 'utf8');              //mysql 인코딩 형식 통일

        //제일 최근에 등록된 아이들 인원수 데이터를 안드로이드로 전송
        $sql = "SELECT * FROM CNT ORDER BY Time DESC limit 1;";

        $result = mysqli_query($conn, $sql);


        $row = mysqli_fetch_assoc($result);

        echo $row['Cnt'];


?>
