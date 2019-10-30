<?php
        //driver는 raspPi에서 보내는 값
        //운전자의 탑승 여부를 알려줌
        $driver = $_POST['drive'];

        //생성된 토큰에 메세지를 전송
        function send_notification ($tokens, $message)
        {
                $url = 'https://fcm.googleapis.com/fcm/send';
                $fields = array(
                        //token은 기존에 생성된 USER테이블에서 불러옴
                         'registration_ids' => $tokens,
                         //message는 아래 참고
                         'data' => $message
                        );

                $headers = array(
                        //FCM 프로젝트 생성시 할당되는 고유코드
                        'FCM CODE',
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

        //유치원 관계자에게만 보내기 위한 쿼리
        $sql3 = "select token from USER where State like 'Admin';";
        
        //제일 최근의 생성된 차량 탑승 인원을 확인
        $sqlc = "select Cnt from CNT order by Time desc limit 1;";
        
        $result3 = mysqli_query($conn,$sql3);
        $resultc = mysqli_query($conn,$sqlc);
        $tokens1 = array();

        // 고온 위험 경고가 발생할 때
        $rowc = mysqli_fetch_assoc($resultc);

        $temp1 = $rowc['Cnt'];
        //int형으로 형변환
        $count = (int)$temp1;

        echo $count;

        //차량 내부 아이가 남아있고, 운전자가 시동을 끄면 알림 전송
        if($count != 0 && $driver == '0'){
              if(mysqli_num_rows($result3) > 0 ){
                      while ($row1 = mysqli_fetch_assoc($result3)) {
                             $tokens1[] = $row1["token"];
                      }

                      $message1 = array("message" => "차량 내 아이가 방치되어있습니다!!!");
                      $message_status1 = send_notification($tokens1, $message1);
                }
        }

        mysqli_close($conn);

        echo $message_status1;
        echo $message_status2;

?>

