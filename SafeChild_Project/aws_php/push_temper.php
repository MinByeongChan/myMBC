<?php
        $temper = $_POST['signal'];

        function send_notification ($tokens, $message)
        {
                $url = 'https://fcm.googleapis.com/fcm/send';
                $fields = array(
                         'registration_ids' => $tokens,
                         'data' => $message
                        );

                $headers = array(
                        'Authorization:key=AAAAfYy0pNk:APA91bG4xSF9kdb8QxJPxtMA4DrEbv-qK8N66$
                        'Content-Type: application/json'
                        );

                $ch = curl_init();
                curl_setopt($ch, CURLOPT_URL, $url);
                curl_setopt($ch, CURLOPT_POST, true);
                curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
                curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
                curl_setopt ($ch, CURLOPT_SSL_VERIFYHOST, 0);
                curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
                curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($fields));

                $result = curl_exec($ch);

                if ($result == FALSE) {
                        die('Curl failed: ' . curl_error($ch));
                }
                curl_close($ch);
                return $result;
       }

        $conn = mysqli_connect("localhost",
                               "mhj",
                               "111111",
                               "proj_manager"
        );
        
        $sql2 = "select token from USER where State like 'Admin';";
        //학부모, 관계자에게만 해당하는 쿼리
        $sql3 = "select token from USER;";

        //temper 데이터는 raspi에서 post되는 갑을 받을 예정
        $sqlc = "select Cnt from CNT order by Time desc limit 1;";

        $result2 = mysqli_query($conn,$sql2);
        $resultc = mysqli_query($conn,$sqlc);

        $tokens1 = array(); // 관계자 테이블 토큰
        $tokens2 = array(); // 학부모 테이블 토큰

        // 고온 위험 경고가 발생할 때
        $rowc = mysqli_fetch_assoc($resultc);
//        $rowt = mysqli_fetch_assoc($resultt);

        $temp1 = $rowc['Cnt'];
        //DB에서 긁어온 Cnt를 int로 형변환
        $count = (int)$temp1;
        
        echo $count;
        echo $temper;

        //차량이 아이 인원수보다 시동이 켜졌을때, 온도가 높은 상황이 더 의미가 있을거같음
        // 차량 내 아이가 남아있고, 온도가 29도 이상일 때 푸쉬알림
        if($count != 0 && $temper == '1'){
                //29도 이상일 떄 온도 경고
                if(mysqli_num_rows($result2) > 0 ){
                        while ($row2 = mysqli_fetch_assoc($result2)) {
                                $tokens2[] = $row2["token"];
                        }

                        //푸쉬알림 메세지
                        $message2 = array("message" => "차량 온도가 높습니다!!!");
                        //긁어온 token과 message를 전송
                        $message_status2 = send_notification($tokens2, $message2);
                }
        }

        mysqli_close($conn);

        echo $message_status1;
        echo $message_status2;

?>



