package com.example.eun.flagmenttest;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.os.IBinder;
import android.widget.Toast;

import static com.example.eun.flagmenttest.DebugMode.minDistance;
import static com.example.eun.flagmenttest.DebugMode.minTime;

public class ExecutionService extends Service {

    LocationManager locationManager;
    GPSListener gpsListener;
    final String phoneNum = "01077020481";
    final String emerNum = "01087591727";
    DebugMode db = new DebugMode();
    public ExecutionService() {
    }

    public void onCreate() {
        super.onCreate();
    }
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        db.r("Test","secondService onStart");
        if(intent == null) {
            return START_STICKY;
        } else {
            processCommand(intent);
        }
        return super.onStartCommand(intent, flags, startId);
    }

    private void processCommand(Intent intent) {
        db.r("Test","sum: "+intent.getIntExtra("signal",0));

        if(intent.getIntExtra("signal",0) >1 ) { // 응급 신고
            db.r("Test","Emeremere: "+intent.getIntExtra("emer",0));
            MyLocation();
            //startActivity(new Intent(Intent.ACTION_CALL).setData(Uri.parse("tel:" + emerNum)));
        } else if (intent.getIntExtra("signal",0) == 1) { // 신고 대기
            db.r("Test","rdrd : "+intent.getIntExtra("emer",0));
            MyLocation();}
    }
    private void MyLocation() {//위치 정보 확인 메소드
        locationManager= (LocationManager) getSystemService(Context.LOCATION_SERVICE);//LocationManager 객체생성 LOCATION_SERVICE사용
        gpsListener= new GPSListener();//LocationListener 인터페이스 정의한 GPSListener 사용
        db.r("Test","위치 전송 시작");

        try {
            locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, minTime, minDistance, gpsListener);//gps를 이용한 위치 요청
            locationManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, minTime, minDistance, gpsListener);//network provider

        } catch (SecurityException ex) {
            db.r("Test", "catch Exception");
            ex.printStackTrace();
        }
        Toast.makeText(getApplicationContext(), "위치 전송 시작", Toast.LENGTH_SHORT).show();

    }
    private class GPSListener implements LocationListener {//LocationLsitener 정의
        public void onLocationChanged(Location location) {//LocationManager 에서 위치정보가 변경되면 호출
            if (location.getProvider().equals(LocationManager.GPS_PROVIDER)) {
                Double latitude = location.getLatitude();
                Double longitude = location.getLongitude();
                Toast.makeText(getApplicationContext(),"gps latitude : " + latitude + " longitude : " + longitude,Toast.LENGTH_SHORT).show();
                db.r("Test", "gps latitude : " + latitude + " longitude : " + longitude);
            } else {
                Double latitude = location.getLatitude();
                Double longitude = location.getLongitude();
                Toast.makeText(getApplicationContext(),"network latitude : " + latitude + " longitude : " + longitude,Toast.LENGTH_SHORT).show();
                db.r("Test", "network latitude : " + latitude + " longitude : " + longitude);
            }
           // SmsManager sms = SmsManager.getDefault();
           // sms.sendTextMessage(phoneNum,null,"latitude : "+latitude.toString()+"\nlongitude : "+longitude.toString(),null,null);
           // Log.d(TAG,"latitude : "+latitude+ " longitude : "+longitude);
        }
        public void onProviderDisabled(String provider) {}
        public void onProviderEnabled(String p) {}
        public void onStatusChanged(String p, int s, Bundle e) {}
    }
    public void onDestroy() {
        super.onDestroy();
        locationManager.removeUpdates(gpsListener);
      //  Log.d(TAG,"SecondService Destroy");
    }
    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }
}
