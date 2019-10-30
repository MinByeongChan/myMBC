package com.example.gta58.child1;

import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class Sub_map extends FragmentActivity implements OnMapReadyCallback {
    // 구글 맵 참조변수 생성
    GoogleMap mMap;
    String myJSON = "";
    String TAG_GPS = "GPSdata";
    String TAG_Latitude = "Latitude";
    String TAG_Longitude = "Longitude";

//    private TextView txtLatitude;
//    private TextView txtLongitude;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.map);

        Button Busbtn = (Button)findViewById(R.id.busBtn);
//        txtLatitude = (TextView)findViewById(R.id.txtlatitude);
//        txtLongitude = (TextView)findViewById(R.id.txtlongitude);

        // SupportMapFragment을 통해 레이아웃에 만든 fragment의 ID를 참조하고 구글맵을 호출한다.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map);
        mapFragment.getMapAsync(this); // getMapAsync must be called on the main thread.


        //버튼을 클릭하면 현재 위치로 카메라 이동
        Busbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                GetData task = new GetData();
                task.execute();
            }
        });
    }


    @Override
    public void onMapReady(GoogleMap googleMap) {
        // 구글 맵 객체를 불러온다.
        mMap = googleMap;

        // 각 도착지 별  위치 설정
        LatLng p1 = new LatLng(37.52619208721502 ,  126.62910393362561 );

        // 구글 맵에 표시할 마커에 대한 옵션 설정
        MarkerOptions makerOptions1 = new MarkerOptions();
        makerOptions1
                .position(p1)
                .title("위치 1");
        makerOptions1.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c1)));

        // 프래그먼트가 실행 되면 초기 지도 위치 좌표를 설정
        GetData task_onMapReady = new GetData();
        task_onMapReady.execute();
    }

    class GetData extends AsyncTask<Void, Void, String> {
        String str, receiveMsg;
        private final String GPSurl = "http://13.124.166.248/maroon5/GPSdata.php";

        @Override
        protected void onPreExecute() {}

        @Override
        protected String doInBackground(Void... params) {
            try {
                URL url = new URL(GPSurl);
                HttpURLConnection con = (HttpURLConnection) url.openConnection();

                con.setReadTimeout(5000);
                con.setConnectTimeout(5000);
                con.setRequestMethod("POST");
                con.setDoInput(true);
                con.connect();

                if (con.getResponseCode() == con.HTTP_OK) {
                    InputStreamReader tmp = new InputStreamReader(con.getInputStream(), "UTF-8");
                    BufferedReader reader = new BufferedReader(tmp);
                    StringBuffer buffer = new StringBuffer();
                    while ((str = reader.readLine()) != null) {
                        buffer.append(str);
                    }
                    receiveMsg = buffer.toString();
                    Log.d("TAG","receiveMsg : "+ receiveMsg);

                    reader.close();
                } else {
                    Log.i("TAG", con.getResponseCode() + "에러");
                }

                return receiveMsg;
            } catch (Exception e) {
                Log.d("TAG", "GetData : Error ", e);
                return null;
            }
        }

        @Override
        protected void onPostExecute(String result) {
            super.onPostExecute(result);
            Log.d("TAG", "result: "+result);
            myJSON = result;
            showGpsData();
        }
    }


    public void showGpsData() {
        String strLat;
        String strLong;
        String tempString;
        double doubleLat = 0;
        double doubleLong = 0;
        double tempDouble;

        try {
            Log.d("TAG", "myJSON: "+myJSON);
            JSONObject jsonObject = new JSONObject(myJSON);
            JSONArray jsonArray = jsonObject.getJSONArray(TAG_GPS);
            for(int i=0; i<jsonArray.length(); i++) {
                JSONObject jsongps = jsonArray.getJSONObject(i);
                strLat = jsongps.getString(TAG_Latitude);
                strLong = jsongps.getString(TAG_Longitude);

                //double타입으로 바꾸어 줌
                //DM 타입을 DD타입으로 변환

                //Latitude
                tempString = strLat.substring(0, 2);
                doubleLat += Double.parseDouble(tempString);
                tempString = strLat.substring(2);
                tempDouble = Math.round((Double.parseDouble(tempString) / 60) * 100000);
                doubleLat +=  tempDouble / 100000;

                //Longitude
                tempString = strLong.substring(0, 3);
                doubleLong += Double.parseDouble(tempString);
                tempString = strLong.substring(3);
                tempDouble = Math.round((Double.parseDouble(tempString) / 60) * 100000);
                doubleLong += tempDouble / 100000;

                Log.d("TAG", "doubleLat: "+doubleLat);
                Log.d("TAG", "doubleLong: "+doubleLong);
            }

            LatLng BusLocation = new LatLng(doubleLat, doubleLong);



            // 구글 맵에 표시할 마커에 대한 옵션 설정
            MarkerOptions makerOptions1 = new MarkerOptions();
            makerOptions1
                    .position(BusLocation)
                    .title("버스 현재 위치!");
            makerOptions1.icon(BitmapDescriptorFactory
                    .fromBitmap(BitmapFactory
                            .decodeResource(getResources(),
                                    R.drawable.gps_bus_px50)
                    )
            );
            mMap.addMarker(makerOptions1);
            //현재 버스 위치로 이동
            mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(BusLocation,17));
//            Toast.makeText(getApplicationContext(), "버스 현재 위치", Toast.LENGTH_SHORT).show();


        } catch (JSONException e){
            Log.d("TAG", "onClick: ", e);
        }
    }
}


