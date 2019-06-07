package com.example.gta58.child1;

import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.firebase.iid.FirebaseInstanceId;
import com.google.firebase.messaging.FirebaseMessaging;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;


public class MainActivity extends AppCompatActivity{
    Button button1;
    Button button2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        FirebaseMessaging.getInstance().subscribeToTopic("test");
        FirebaseInstanceId.getInstance().getToken();

        TextView adminText = (TextView)findViewById(R.id.adminText);
        Button updateButton = (Button)findViewById(R.id.updateButton);


        Intent intent = getIntent();
        String userID = intent.getStringExtra("userID");

        if(userID.equals("admin")){
            adminText.setVisibility(View.VISIBLE);
        }

        updateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new BackgroundTask1().execute();
                new BackgroundTask2().execute();
                new BackgroundTask3().execute();

            }
        });

        button1=(Button) findViewById(R.id.button1);                                                        //만든 버튼객체에 접근하는 메소드

        button1.setOnClickListener(new View.OnClickListener() {//클릭하면 작동하는 이벤트메소드 정의
            @Override
            public void onClick(View view) {                                                            //버튼을 클릭했을때 작동하기 원하는 코드 여기에 작성

                Intent mlntent=new Intent(Intent.ACTION_VIEW, Uri.parse("tel:/010-7702-0481"));
                startActivity(mlntent);                                                                     //버튼 클릭하면 전화 거는 화면으로 이동
            }
        });

        button2=(Button) findViewById(R.id.button2);

        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent mlntent=new Intent(Intent.ACTION_VIEW, Uri.parse("tel:/010-1234-5678"));
                startActivity(mlntent);
                //Toast.makeText(getApplicationContext(),"버스기사님 연결중...", Toast.LENGTH_SHORT).show();
            }
        });
    }

    class BackgroundTask1 extends AsyncTask<Void, Void, String> {
        String target;
        TextView countText = (TextView)findViewById(R.id.countText);

        @Override
        protected void onPreExecute() {
            target = "http://13.124.166.248/count1.php";
        }

        @Override
        protected String doInBackground(Void... voids) {

            try{
                URL url = new URL(target);//URL 객체 생성
                                                                                                                                            //URL을 이용해서 웹페이지에 연결하는 부분
                HttpURLConnection httpURLConnection = (HttpURLConnection)url.openConnection();
                                                                                                                                            //바이트단위 입력스트림 생성 소스는 httpURLConnection
                InputStream inputStream = httpURLConnection.getInputStream();
                                                                                                                                            //웹페이지 출력물을 버퍼로 받음 버퍼로 하면 속도가 더 빨라짐
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
                String temp;
                                                                                                                                            //문자열 처리를 더 빠르게 하기 위해 StringBuilder클래스를 사용함
                StringBuilder stringBuilder = new StringBuilder();
                                                                                                                                                //한줄씩 읽어서 stringBuilder에 저장함
                while((temp = bufferedReader.readLine()) != null){
                    stringBuilder.append(temp + "\n");                                                                                      //stringBuilder에 넣어줌
                }

                //사용했던 것도 다 닫음
                bufferedReader.close();
                inputStream.close();
                httpURLConnection.disconnect();
                return stringBuilder.toString().trim();                                                                                     //trim은 앞뒤의 공백을 제거함

            }catch(Exception e){
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Void... values) {
            super.onProgressUpdate(values);
        }

        @Override
        protected void onPostExecute(String result) {
            countText.setText(result+"명 / 30명");
        }

    }

    class BackgroundTask2 extends AsyncTask<Void, Void, String> {
        String target;
        TextView temText = (TextView)findViewById(R.id.temText);

        @Override
        protected void onPreExecute() {
            //Value.php은 파싱으로 가져올 웹페이지
            target = "http://13.124.166.248/temdata1.php";
        }

        @Override
        protected String doInBackground(Void... voids) {

            try{
                URL url = new URL(target);//URL 객체 생성

                //URL을 이용해서 웹페이지에 연결하는 부분
                HttpURLConnection httpURLConnection = (HttpURLConnection)url.openConnection();

                //바이트단위 입력스트림 생성 소스는 httpURLConnection
                InputStream inputStream = httpURLConnection.getInputStream();

                //웹페이지 출력물을 버퍼로 받음 버퍼로 하면 속도가 더 빨라짐
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
                String temp;

                //문자열 처리를 더 빠르게 하기 위해 StringBuilder클래스를 사용함
                StringBuilder stringBuilder = new StringBuilder();

                //한줄씩 읽어서 stringBuilder에 저장함
                while((temp = bufferedReader.readLine()) != null){
                    stringBuilder.append(temp + "\n");//stringBuilder에 넣어줌
                }

                //사용했던 것도 다 닫아줌
                bufferedReader.close();
                inputStream.close();
                httpURLConnection.disconnect();
                return stringBuilder.toString().trim();//trim은 앞뒤의 공백을 제거함

            }catch(Exception e){
                e.printStackTrace();
            }
            return null;

        }

        @Override
        protected void onProgressUpdate(Void... values) {
            super.onProgressUpdate(values);
        }

        @Override
        protected void onPostExecute(String result) {
            temText.setText(result+"°C");
        }

    }

    class BackgroundTask3 extends AsyncTask<Void, Void, String> {
        String target;
        ImageView drivero = (ImageView)findViewById(R.id.drivero);

        @Override
        protected void onPreExecute() {
            //Value.php은 파싱으로 가져올 웹페이지
            target = "http://13.124.166.248/driver1.php";
        }

        @Override
        protected String doInBackground(Void... voids) {

            try{
                URL url = new URL(target);//URL 객체 생성

                //URL을 이용해서 웹페이지에 연결하는 부분
                HttpURLConnection httpURLConnection = (HttpURLConnection)url.openConnection();

                //바이트단위 입력스트림 생성 소스는 httpURLConnection
                InputStream inputStream = httpURLConnection.getInputStream();

                //웹페이지 출력물을 버퍼로 받음 버퍼로 하면 속도가 더 빨라짐
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
                String temp;

                //문자열 처리를 더 빠르게 하기 위해 StringBuilder클래스를 사용함
                StringBuilder stringBuilder = new StringBuilder();

                //한줄씩 읽어서 stringBuilder에 저장함
                while((temp = bufferedReader.readLine()) != null){
                    stringBuilder.append(temp + "\n");//stringBuilder에 넣어줌
                }

                //사용했던 것도 다 닫아줌
                bufferedReader.close();
                inputStream.close();
                httpURLConnection.disconnect();
                return stringBuilder.toString().trim();//trim은 앞뒤의 공백을 제거함

            }catch(Exception e){
                e.printStackTrace();
            }
            return null;

        }

        @Override
        protected void onProgressUpdate(Void... values) {
            super.onProgressUpdate(values);
        }

        @Override
        protected void onPostExecute(String result) {
            int state = Integer.parseInt(result);
            if(state == 0){
                drivero.setVisibility(View.INVISIBLE);
            }
            else{
                drivero.setVisibility(View.VISIBLE);
            }

        }

    }


}

