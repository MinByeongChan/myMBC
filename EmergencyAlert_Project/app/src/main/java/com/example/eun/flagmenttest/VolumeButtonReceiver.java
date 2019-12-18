package com.example.eun.flagmenttest;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import static com.example.eun.flagmenttest.DebugMode.M_PUSH;

public class VolumeButtonReceiver extends BroadcastReceiver {
    static int count = 0;
    long now = System.currentTimeMillis();
    static long past_time;
    long differ;

    DebugMode db = new DebugMode();

    @Override
    public void onReceive(Context context, Intent intent) {

        differ = now-past_time;
       db.r("Test","볼륨버튼 count :"+count);
        if(differ<100&&differ>10) {
            count++;
            if(count>M_PUSH) { //대강 3초 실행
                Intent serviceIntent = new Intent(context,MainService.class);
                serviceIntent.putExtra("Value",2);
                context.startService(serviceIntent);
                count=0;
            }
        }
        else count=0;
        past_time=now;


    }
}


                    /* 브로드캐스트 리시버-> 메인 액티비티
                    Intent i = new Intent( context, MainActivity.class );
                    PendingIntent pi = PendingIntent.getActivity(context, 0, i, PendingIntent.FLAG_ONE_SHOT);
                    try {
                        pi.send();
                    } catch (PendingIntent.CanceledException e) {
                        e.printStackTrace();
                    }*/
