package com.example.gta58.child1;

import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.support.v7.app.AlertDialog;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.android.volley.Response;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

import org.json.JSONException;
import org.json.JSONObject;

public class Sub_map extends FragmentActivity implements OnMapReadyCallback {
    // 구글 맵 참조변수 생성
    GoogleMap mMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.map);

        Button Busbtn = (Button)findViewById(R.id.busBtn);

        // SupportMapFragment을 통해 레이아웃에 만든 fragment의 ID를 참조하고 구글맵을 호출한다.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map);
        mapFragment.getMapAsync(this); // getMapAsync must be called on the main thread.

        //버튼을 클릭하면 현재 위치로 카메라 이동
        Busbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Response.Listener<String> responseListener = new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        try{
                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success = jsonResponse.getBoolean("success");

                            //서버에서 보내준 값이 true이면?
                            if(success){
                                String latitude = jsonResponse.getString("latitude");
                                String longitude = jsonResponse.getString("longitude");

                                //double타입으로 바꾸어 줘야함!!
                                double strLati = Double.parseDouble(latitude);
                                double strLongi = Double.parseDouble(longitude);
                                LatLng BusLocation = new LatLng(strLati, strLongi);

                                //현재 버스 위치로 이동
                                mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(BusLocation,17));

                                Toast.makeText(getApplicationContext(), "GPS 불러오기 성공", Toast.LENGTH_SHORT).show();
                            }

                            else{
                                AlertDialog.Builder builder = new AlertDialog.Builder(Sub_map.this);
                                Toast.makeText(getApplicationContext(), "GPS 불러오기 실패", Toast.LENGTH_SHORT).show();
                                builder.setMessage("다시 시도해주세요")
                                        .setNegativeButton("확인", null)
                                        .create()
                                        .show();
                            }
                        }catch(JSONException e){
                            e.printStackTrace();
                        }
                    }
                };
            }
        });
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        // 구글 맵 객체를 불러온다.
        mMap = googleMap;

        // 각 도착지 별  위치 설정
        LatLng p1 = new LatLng(37.52619208721502 ,  126.62910393362561 );
        LatLng p2 = new LatLng(37.5269577629917  ,  126.62904923435793 );
        LatLng p3 = new LatLng( 37.52878777560245 ,  126.62793147402526  );
        LatLng p4 = new LatLng( 37.52833201884467 , 126.62484524091171 );
        LatLng p5 = new LatLng(37.52660909213433 , 126.62420903318785  );
        LatLng p6 = new LatLng(37.524623722301634  , 126.62321216939594  );
        LatLng p7 = new LatLng(37.5249427110156  , 126.62719827882526  );
        LatLng kindergarten = new LatLng(37.525075280511025  ,  126.62852403133323  );
        // 구글 맵에 표시할 마커에 대한 옵션 설정
        MarkerOptions makerOptions1 = new MarkerOptions();
        makerOptions1
                .position(p1)
                .title("위치 1");
        makerOptions1.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c1)));

        MarkerOptions makerOptions2 = new MarkerOptions();
        makerOptions2
                .position(p2)
                .title("위치 2");
        makerOptions2.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c2)));

        MarkerOptions makerOptions3 = new MarkerOptions();
        makerOptions3
                .position(p3)
                .title("위치 3");
        makerOptions3.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c3)));

        MarkerOptions makerOptions4 = new MarkerOptions();
        makerOptions4
                .position(p4)
                .title("위치 4");
        makerOptions4.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c4)));

        MarkerOptions makerOptions5 = new MarkerOptions();
        makerOptions5
                .position(p5)
                .title("위치 5");
        makerOptions5.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c5)));

        MarkerOptions makerOptions6 = new MarkerOptions();
        makerOptions6
                .position(p6)
                .title("위치 6");
        makerOptions6.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c6)));

        MarkerOptions makerOptions7 = new MarkerOptions();
        makerOptions7
                .position(p7)
                .title("위치 7");
        makerOptions7.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.c7)));

        MarkerOptions makerkindergarten = new MarkerOptions();
        makerkindergarten
                .position(kindergarten)
                .title("유치원 도착");
        makerkindergarten.icon(BitmapDescriptorFactory.fromBitmap(BitmapFactory.decodeResource(getResources(),R.drawable.ck)));

        // 마커를 생성한다.
        mMap.addMarker(makerOptions1);
        mMap.addMarker(makerOptions2);
        mMap.addMarker(makerOptions3);
        mMap.addMarker(makerOptions4);
        mMap.addMarker(makerOptions5);
        mMap.addMarker(makerOptions6);
        mMap.addMarker(makerOptions7);
        mMap.addMarker(makerkindergarten);

        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p1,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p2,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p3,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p4,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p5,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p6,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(p7,17));
        mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(kindergarten,17));


    }

}
