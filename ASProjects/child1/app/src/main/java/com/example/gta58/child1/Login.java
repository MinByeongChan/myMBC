package com.example.gta58.child1;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

public class Login extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        //강의에서 final을 추가시켜줌
        final EditText idinput = (EditText) findViewById(R.id.idinput);
        final EditText passwordinput = (EditText) findViewById(R.id.passwordinput);
        final Button btn3 = (Button) findViewById(R.id.btn3);
        final Button btn4 = (Button) findViewById(R.id.btn4);


        btn3.setOnClickListener(new View.OnClickListener() {


            @Override

            public void onClick(View view) {

                final String userID = idinput.getText().toString();
                final String userPassword = passwordinput.getText().toString();

                Response.Listener<String> responseListener = new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        try{
                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success = jsonResponse.getBoolean("success");
                                                                                                                                     //서버에서 보내준 값이 true이면?
                            if(success){

                                String userID = jsonResponse.getString("userID");
                                String userPassword = jsonResponse.getString("userPassword");
                                Toast.makeText(getApplicationContext(), "로그인 성공", Toast.LENGTH_SHORT).show();

                                //로그인에 성공했으므로 MainActivity로 넘어감
                                Intent intent = new Intent(Login.this, MainActivity.class);
                                intent.putExtra("userID", userID);
                                finish();
                                Login.this.startActivity(intent);

                            }
                            //로그인 실패시
                            else{
                                AlertDialog.Builder builder = new AlertDialog.Builder(Login.this);
                                Toast.makeText(getApplicationContext(), "로그인 실패", Toast.LENGTH_SHORT).show();
                                builder.setMessage("아이디 혹은 비밀번호를 다시 확인해주세요.")
                                        .setNegativeButton("확인", null)
                                        .create()
                                        .show();
                            }
                        }catch(JSONException e){
                            e.printStackTrace();
                        }
                    }
                };
                LoginRequest loginRequest = new LoginRequest(userID, userPassword, responseListener);
                RequestQueue queue = Volley.newRequestQueue(Login.this);
                queue.add(loginRequest);

            }

        });
        btn4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent1= new Intent(Login.this, Signon.class);
                startActivity(intent1);
            }

        });

    }
}
