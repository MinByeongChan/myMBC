package com.example.eun.flagmenttest;

import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.IBinder;
import android.os.Vibrator;
import android.telephony.SmsManager;
import android.util.Log;
import android.widget.Toast;

public class MainService extends Service {
    final boolean GO = true;
    final boolean STOP = false;
    CountDownTimer countDown;
    boolean count_dir = STOP;
    boolean r_dir = STOP;//신고대기 방향
    boolean e_dir = STOP; //즉시신고 방향
    boolean policeNum = STOP;
    int count = 0;
    DebugMode db = new DebugMode();
    final DB database = new DB();
    MyThread myThread;
    LocationManager locationManager;
    GPSListener gpsListener;
    Double latitude,longitude;
    String police = "01087591727";

    public MainService() {}
    @Override
    public void onCreate() {
        super.onCreate();
        db.r("Test","Service onCreate");

    }
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        db.r("Test","Service onStartCommand");
        if(intent == null) {
            return START_STICKY;
        } else {
            processCommand(intent);
        }
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        db.r("Test","MainService destroy");
        Toast.makeText(getApplicationContext(),"상황 종료",Toast.LENGTH_SHORT).show();
        super.onDestroy();
    }
    @Override
    public IBinder onBind(Intent intent) {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    private void processCommand(Intent intent) {
        int value = intent.getIntExtra("Value", 0);
        db.r("Test","Value : "+value);
        count ++;
        if(count == 1) {
            myThread = new MyThread();
            myThread.start();
            MyLocation();

            if(value<3) {
                r_dir=!r_dir;
            } else {
                e_dir=!e_dir;
            }
        } else if (count == 2) {
            if(e_dir==GO) {
                e_dir=STOP;
                r_dir=STOP;
            } else {
                if(value==1) {
                    r_dir=STOP;
                } else {
                    r_dir=!r_dir;
                    e_dir=!e_dir;
                }
            }

        }else {
            e_dir=STOP;
            r_dir=STOP;
        }
        Log.i("Test", "e_dir : " + e_dir);
        Log.i("Test", "r_dir : " + r_dir);

       Exe();


    }

    final void Ready() {
        vibrator(1000);
        if(database.r_e_timer!=0) {
            CountDown(database.r_e_timer, 1000);
        }
        Toast.makeText(getApplicationContext(),"신고대기 실행",Toast.LENGTH_SHORT).show();

    }
    public void Emergency() {
        if(count_dir) {
            count_dir=STOP;
            countDown.cancel();
        }
        Toast.makeText(getApplicationContext(),"즉시신고 실행",Toast.LENGTH_SHORT).show();
        if(database.phone!=0) {
            Phone();
        }
        policeNum=GO;//sms 112 문자신고
        vibrator(1000);




       /* boolean temp = e_dir;
        e_dir=!temp;
        if(e_dir==GO) {
            Toast.makeText(getApplicationContext(), "긴급상황 시작", Toast.LENGTH_LONG).show();
        } else if(e_dir == STOP) {
            Toast.makeText(getApplicationContext(), "긴급상황 정지", Toast.LENGTH_LONG).show();
            this.onDestroy();// not yet
        }

        stopService(exIntent);//not yet*/


    }
    public void vibrator(int v) {
        Vibrator vibrator = (Vibrator)getSystemService(Context.VIBRATOR_SERVICE);
        vibrator.vibrate(v);
    }
    public void ExeTimer() {

        final Global global = (Global)getApplication();

        Intent popupIntent = new Intent(MainService.this, Translucent.class);
        PendingIntent pi = PendingIntent.getActivity(MainService.this, 0, popupIntent, PendingIntent.FLAG_ONE_SHOT);
        try{
            pi.send();
        }
        catch(Exception e){
            Toast.makeText(MainService.this, e.toString(), Toast.LENGTH_LONG);
        }

        Log.i("Test","global.getSafeDir() : "+global.getSafeDir());
        final CountDownTimer countDownTimer1 = new CountDownTimer(5000,1000) {
           @Override
           public void onTick(long l) {
               if (global.getSafeDir()) { // 즉시 신고 취소
                   Log.i("Test", "즉시신고 취소");
                   e_dir = false;
                   r_dir = false;
                   global.ChangeSafeDir(false);
                   this.cancel();
                   Exe();
               }
           }
           @Override
           public void onFinish() {
               Log.i("Test", "즉시신고 시작");
               Emergency();
               global.ChangeSafeDir(false);
           }
       }.start();
    }
    public void Exe() {


        if(e_dir == GO) { // 긴급상황
            ExeTimer();
        } else if(r_dir == GO) { // 신고 대기
            Ready();
        }
        if(e_dir==STOP && r_dir==STOP){ //상황종료
            vibrator(1000);
          //  Toast.makeText(getApplicationContext(),"상황종료",Toast.LENGTH_SHORT).show();
            if(count_dir) {
                count_dir=STOP;
                countDown.cancel();
            }
            locationManager.removeUpdates(gpsListener);
            myThread.interrupt();
            stopSelf();
        }
    }

    public void CountDown(final int max, int tick) {
        count_dir=GO;
        countDown = new CountDownTimer(max, tick) {
            @Override
            public void onTick(long l) {

                    int count = (int)l/1000;
                    if(count%10==0){
                        db.r("Test","즉시신고 남은 시간 : "+(count));
                   Toast.makeText(getApplicationContext(), "즉시신고 남은 시간 : "+(count), Toast.LENGTH_SHORT).show();
                    }


            }

            @Override
            public void onFinish() {
                count_dir=STOP;
                e_dir =GO;
                r_dir=STOP;
                count++;
               Exe();
            }
        }.start();

    }
    public void SMS() {
        String str ;
        db.r("Test","\n112 : "+policeNum);
        if(database.gps!=0 && latitude!=null) {
            db.r("Test", "\n경도 : " + latitude + "\n위도 : " + longitude);
            str = "도와주세요\n" + "경도 : "+latitude + "\n위도 : "+longitude;
        } else str = "도와주세요\n";

        db.r("Test", "도와주세요");



       for(int i = 0 ; i< database.userNum.length;i++){
          // SmsManager sms = SmsManager.getDefault();//사용자 지정 번호
           //sms.sendTextMessage(database.userNum[i],null,str,null,null);
           db.r("Test", "userNum : " +database.userNum[i]);
       }


        if(policeNum) {// 경찰 문자
            SmsManager sms = SmsManager.getDefault();
            sms.sendTextMessage(police,null,str,null,null);
        }
       SmsManager sms = SmsManager.getDefault();//사용자 지정 번호
        sms.sendTextMessage("01077020481",null,str,null,null);
        // Log.d(TAG,"latitude : "+latitude+ " longitude : "+longitude);
    }
    public void Phone () {
        db.r("Test", "112 전화");

            Toast.makeText(getApplicationContext(),"112 전화 중",Toast.LENGTH_SHORT).show();
            startActivity(new Intent(Intent.ACTION_CALL).setData(Uri.parse("tel:" + police)));
    }

    class DB {
        private int r_e_timer=30*1000; // 즉시신고 전환 대기 시간(신고 대기시)
        private int sms=10*1000; // sms 문자 송신 대기 시간
        private int phone=1; // 전화 여부
        private int gps=1; // gps 여부
        private int volumeButtonTime = 3*20;
        String userNum[]={"010","101"};
    }

    class MyThread extends Thread {
        boolean thread_dir=true;
        @Override
        public void run() {
            while(thread_dir) {
                try {
                    if(database.sms==0)interrupt();
                    SMS();
                    sleep(database.sms);

                }catch (InterruptedException e) {}
            }
            super.run();
        }

        @Override
        public void interrupt() {
            thread_dir=false;
            super.interrupt();
        }


    }
    private void MyLocation() {//위치 정보 확인 메소드
        locationManager= (LocationManager) getSystemService(Context.LOCATION_SERVICE);//LocationManager 객체생성 LOCATION_SERVICE사용
        gpsListener= new GPSListener();//LocationListener 인터페이스 정의한 GPSListener 사용

        try {
            locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 5000, 0, gpsListener);//gps를 이용한 위치 요청
            locationManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 5000, 0, gpsListener);//network provider

        } catch (SecurityException ex) {
            ex.printStackTrace();
        }
    }
    private class GPSListener implements LocationListener {//LocationLsitener 정의
        public void onLocationChanged(Location location) {//LocationManager 에서 위치정보가 변경되면 호출
            if (location.getProvider().equals(LocationManager.GPS_PROVIDER)) {
                latitude = location.getLatitude();
               longitude = location.getLongitude();
               // db.r("Test", "gps latitude : " + latitude + " longitude : " + longitude);
            } else {
                latitude = location.getLatitude();
                longitude = location.getLongitude();
               // db.r("Test", "network latitude : " + latitude + " longitude : " + longitude);
            }

        }
        public void onProviderDisabled(String provider) {}
        public void onProviderEnabled(String p) {}
        public void onStatusChanged(String p, int s, Bundle e) {}
    }


}
