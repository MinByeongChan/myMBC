<?php
        $db = mysqli_connect(                         //mysql 연결
          'localhost',
          'mhj',
          '111111',
          'proj_manager');

        if(!$db){
            echo "disconnect : 실패";
        }

        mysqli_set_charset($db, 'utf8');              //mysql 인코딩 형식 통일


        //GPS테이블 안에서 가장 최근에 등록된 데이터를 안드로이드 앱으로 전송
        $sql = "SELECT Latitude, Longitude FROM GPS ORDER BY ID DESC limit 1;";

        $result = mysqli_query($db, $sql);
        $data = array();

        if($result) {
           while($row = mysqli_fetch_array($result)){
                //배열을 통째로 전송
                //1행은 위도, 2행은 경도
                array_push($data,
                    array('Latitude'=>$row[0],
                    'Longitude'=>$row[1]
              ));
           }

            //json형식으로 전송
           header('Content-Type: application/json; charset=utf8');
           $json = json_encode(array("GPSdata"=>$data), JSON_PRETTY_PRINT+JSON_UNESCAPED_UNICODE);

           echo $json;
        }

        else {
           echo "ERROR";
           echo mysqli_error($db);
        }

        mysqli_close($db);
?>