package com.example.gta58.child1;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.os.Build;
import android.support.v4.app.NotificationCompat;

import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

/**
 * Created by mbc04 on 2019-05-27.
 */

public class MyFirebaseMessagingService extends FirebaseMessagingService{

    public NotificationManager mManager;

    @Override
    public void onMessageReceived(RemoteMessage remoteMessage) {
        showNotification(remoteMessage.getData().get("message"));
    }

    //알림 전송함수
    private void showNotification(String message) {
        String CHANNEL_ID = null;
        CHANNEL_ID = "Chan_channel_01";

        // 채널 생성함수
        createChannels(CHANNEL_ID);
        // 푸쉬알림 생성함수
        NotificationCompat.Builder mBuilder = getBuilder(CHANNEL_ID, message);
        // 푸쉬알림 실행
        getManager().notify(0, mBuilder.build());
    }

    // 채널 생성함수
    public void createChannels(String CHANNEL_ID){
        // 안드로이드 API 26 이상일 때 동작
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            String Description = "This is Chan channel";
            CharSequence name = "Chan_channel";
            int importance = getManager().IMPORTANCE_LOW;

            //채널 생성
            NotificationChannel mChannel = new NotificationChannel(CHANNEL_ID, name, importance);
            //채널 설정
            mChannel.setDescription(Description);
            mChannel.enableLights(true);
            mChannel.setLightColor(Color.RED);
            mChannel.enableVibration(true);
            //NotificationManager를 이용한 채널 생성
            getManager().createNotificationChannel(mChannel);
        }
    }

    // NotificationManager 따로 생성
    public NotificationManager getManager(){
        if(mManager == null){
            mManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        }
        return mManager;
    }

    //푸쉬알림 함수
    public NotificationCompat.Builder getBuilder(String CHANNEL_ID, String message){
        //푸쉬알림을 누르면 이동하는 인텐트 레이아웃
        Intent i = new Intent(this, MainActivity.class);
        i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);

        PendingIntent pendingIntent = PendingIntent.getActivity(
                this,
                0,
                i,
                PendingIntent.FLAG_UPDATE_CURRENT);

        //푸쉬알림 생성
        NotificationCompat.Builder builder =
                new NotificationCompat.Builder(getApplicationContext(), CHANNEL_ID)
                        .setContentTitle("위험해요!")// 알림 타이틀
                        .setContentText(message)// 서버에서 보내는 알림 메세지
                        //푸쉬알림 설정
                        .setSmallIcon(R.drawable.icon)
                        .setContentIntent(pendingIntent)
                        .setPriority(Notification.PRIORITY_HIGH)
                        .setDefaults(Notification.DEFAULT_VIBRATE)
                        .setAutoCancel(true);
        return builder;
    }
}
