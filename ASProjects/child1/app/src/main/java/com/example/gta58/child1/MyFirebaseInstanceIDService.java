package com.example.gta58.child1;

import com.google.firebase.messaging.FirebaseMessagingService;


/**
 * Created by mbc04 on 2019-05-27.
 */

public abstract class MyFirebaseInstanceIDService extends FirebaseMessagingService {
//
//    @Override
//    public void onNewToken(String token) {
//        Log.d("TAG", "Refreshed token: " + token);
//
//        // If you want to send messages to this application instance or
//        // manage this apps subscriptions on the server side, send the
//        // Instance ID token to your app server.
//        registerToken(token);
//    }
//
////    public void onTokenRefresh()  {
////        String token = FirebaseInstanceId.getInstance().getToken();
////        Log.d("TAG", " getToken " + token);
////        registerToken(token);
////
////    }
//
//    public void registerToken(String token){
//        OkHttpClient client = new OkHttpClient();
//        RequestBody body = new FormBody.Builder()
//                .add("Token", token)
//                .build();
//        Log.d("TAG", " request ");
//
//        Request request = new Request.Builder()
//                .url("http://13.124.166.248/Register_mbc2.php")
//                .post(body)
//                .build();
//        Log.d("TAG", " url");
//
//        try{
//            client.newCall(request).execute();
//        }catch (IOException e){
//            e.printStackTrace();
//        }
//    }
}

