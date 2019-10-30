package com.example.gta58.child1;

import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * Created by mbc04 on 2019-07-03.
 */

public class Sub_info extends AppCompatActivity{
    ImageButton imgrefresh;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.info);
        imgrefresh = findViewById(R.id.ImgRefresh);

//        RefreshCnt Init_refreshCnt = new RefreshCnt();;
//        RefreshTemper Init_refreshTemper = new RefreshTemper();

//        Init_refreshCnt.execute();
//        Init_refreshTemper.execute();

        imgrefresh.setOnClickListener(new View.OnClickListener() {
//            RefreshCnt refreshCnt = new RefreshCnt();;
//            RefreshTemper refreshTemper = new RefreshTemper();

            @Override
            public void onClick(View v) {
                new RefreshTemper().execute();
                new RefreshCnt().execute();
                new RefreshHumi().execute();
            }
        });
    }


    public class RefreshTemper extends AsyncTask<Void, Void, String> {
        String temperUrl;
        TextView temText = (TextView)findViewById(R.id.temText);

        @Override
        protected void onPreExecute() {
            //Value.php은 파싱으로 가져올 웹페이지
            temperUrl = "http://13.124.166.248/maroon5/temdata1.php";
        }

        @Override
        protected String doInBackground(Void... voids) {

            try{
                URL temperurl = new URL(temperUrl);//URL 객체 생성
                HttpURLConnection httpURLConnectionTem = (HttpURLConnection)temperurl.openConnection();
                InputStream inputStreamTem = httpURLConnectionTem.getInputStream();
                BufferedReader bufferedReaderTem = new BufferedReader(new InputStreamReader(inputStreamTem));

                String temp;
                StringBuilder stringBuilderTem = new StringBuilder();

                //한줄씩 읽어서 stringBuilder에 저장함
                while((temp = bufferedReaderTem.readLine()) != null){
                    stringBuilderTem.append(temp + "\n");//stringBuilder에 넣어줌
                }

                //사용했던 것도 다 닫아줌
                bufferedReaderTem.close();
                inputStreamTem.close();
                httpURLConnectionTem.disconnect();
                return stringBuilderTem.toString().trim();//trim은 앞뒤의 공백을 제거함

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

    public class RefreshHumi extends AsyncTask<Void, Void, String> {
        String humiUrl;
        TextView humiText = (TextView)findViewById(R.id.humiText);

        @Override
        protected void onPreExecute() {
            //Value.php은 파싱으로 가져올 웹페이지
            humiUrl = "http://13.124.166.248/maroon5/humi1.php";
        }

        @Override
        protected String doInBackground(Void... voids) {

            try{
                URL humiurl = new URL(humiUrl);//URL 객체 생성
                HttpURLConnection httpURLConnectionTem = (HttpURLConnection)humiurl.openConnection();
                InputStream inputStreamTem = httpURLConnectionTem.getInputStream();
                BufferedReader bufferedReaderTem = new BufferedReader(new InputStreamReader(inputStreamTem));

                String temp;
                StringBuilder stringBuilderTem = new StringBuilder();

                //한줄씩 읽어서 stringBuilder에 저장함
                while((temp = bufferedReaderTem.readLine()) != null){
                    stringBuilderTem.append(temp + "\n");//stringBuilder에 넣어줌
                }

                //사용했던 것도 다 닫아줌
                bufferedReaderTem.close();
                inputStreamTem.close();
                httpURLConnectionTem.disconnect();
                return stringBuilderTem.toString().trim();//trim은 앞뒤의 공백을 제거함

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
            humiText.setText(result+"%");
        }

    }

    public class RefreshCnt extends AsyncTask<Void, Void, String> {
        String countUrl;
        TextView countText = (TextView)findViewById(R.id.countText);

        @Override
        protected void onPreExecute() {
            countUrl = "http://13.124.166.248/maroon5/count1.php";
        }

        @Override
        protected String doInBackground(Void... voids) {

            try{
                URL url = new URL(countUrl);//URL 객체 생성
                HttpURLConnection httpURLConnectionCnt = (HttpURLConnection)url.openConnection();
                InputStream inputStreamCnt = httpURLConnectionCnt.getInputStream();
                BufferedReader bufferedReaderCnt = new BufferedReader(new InputStreamReader(inputStreamCnt));
                String temp;
                StringBuilder stringBuilderCnt = new StringBuilder();
                while((temp = bufferedReaderCnt.readLine()) != null){
                    stringBuilderCnt.append(temp + "\n");                                                                                      //stringBuilder에 넣어줌
                }

                //사용했던 것도 다 닫음
                bufferedReaderCnt.close();
                inputStreamCnt.close();
                httpURLConnectionCnt.disconnect();
                return stringBuilderCnt.toString().trim();                                                                                     //trim은 앞뒤의 공백을 제거함

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
            countText.setText(result+"명 ");
        }
    }
}
