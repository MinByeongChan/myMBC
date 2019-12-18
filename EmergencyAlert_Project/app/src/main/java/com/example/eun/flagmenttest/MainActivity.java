package com.example.eun.flagmenttest;

import android.Manifest;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.gun0912.tedpermission.PermissionListener;
import com.gun0912.tedpermission.TedPermission;

import java.util.ArrayList;

import static android.Manifest.permission.CALL_PHONE;
import static android.Manifest.permission.SEND_SMS;


public class MainActivity extends AppCompatActivity {

    Button homeBtn, menuBtn, helpBtn;
    Home homeFragment;
    Menu menuFragment;
    Help helpFragment;
    DebugMode db = new DebugMode();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        db.r("Test","onCreate");
       permission();
        //Intent intent = new Intent(this,MainService.class);
        //startService(intent);

        homeFragment = new Home();
        menuFragment = new Menu();
        helpFragment = new Help();


        homeBtn = (Button) findViewById(R.id.homeBtn);
        menuBtn = (Button) findViewById(R.id.menuBtn);
        helpBtn = (Button) findViewById(R.id.helpBtn);
        getSupportFragmentManager().beginTransaction().add(R.id.container, homeFragment).commit();

        homeBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getSupportFragmentManager().beginTransaction().replace(R.id.container, homeFragment).commit();
            }
        });

        menuBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getSupportFragmentManager().beginTransaction().replace(R.id.container, menuFragment).commit();
            }
        });
        helpBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getSupportFragmentManager().beginTransaction().replace(R.id.container, helpFragment).commit();
            }
        });
    }

    @Override
    protected void onPause() {
        Log.d("Test", "main_onPause");
        super.onPause();
    }

    public void onStartService(int Value) {
       Intent serviceIntent = new Intent(MainActivity.this,MainService.class);
        serviceIntent.putExtra("Value",Value);
        startService(serviceIntent);
    }
    public void permission() {

        PermissionListener permissionlistener = new PermissionListener() {
            @Override
            public void onPermissionGranted() {
                Toast.makeText(MainActivity.this, "권한 허가", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onPermissionDenied(ArrayList<String> deniedPermissions) {
                Toast.makeText(MainActivity.this, "권한 거부\n" + deniedPermissions.toString(), Toast.LENGTH_LONG).show();
            }


        };

        TedPermission.with(this)
                .setPermissionListener(permissionlistener)
                .setRationaleMessage("GPS를 사용하기 위한 권한 설정")
                .setDeniedMessage("거부 하셨습니다. 필요한 경우 <설정>탭에서 바꾸실수 있습니다.")
                .setPermissions(Manifest.permission.ACCESS_FINE_LOCATION,Manifest.permission.VIBRATE,Manifest.permission.ACCESS_COARSE_LOCATION,SEND_SMS,CALL_PHONE)
                .check();


    }

}

