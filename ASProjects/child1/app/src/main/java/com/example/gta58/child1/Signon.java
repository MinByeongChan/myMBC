package com.example.gta58.child1;

import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.IdRes;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;
import com.google.firebase.iid.FirebaseInstanceId;

import org.json.JSONException;
import org.json.JSONObject;


public class Signon extends AppCompatActivity {
    public String userGender = "여성";
    public static String userState = "학부모";
    private AlertDialog dialog;
    private boolean validate = false;
    private int stateValue=0;


    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signon);

        final EditText nameText = (EditText) findViewById(R.id.nameText);
        final EditText idText = (EditText) findViewById(R.id.idText);
        final EditText passwordText = (EditText) findViewById(R.id.passwordText);
        final EditText checkpasswordText = (EditText) findViewById(R.id.checkpasswordText);
        final EditText emailText = (EditText) findViewById(R.id.emailText);
        final ImageView setImage = (ImageView) findViewById(R.id.setImage);
        final Button registerButton = (Button) findViewById(R.id.registerButton);
        final Button validateButton = (Button) findViewById(R.id.validateButton);
        final RadioGroup gender = (RadioGroup) findViewById(R.id.genderGroup);

        final RadioGroup stateRG = (RadioGroup) findViewById(R.id.state);
        final EditText codeText = (EditText) findViewById(R.id.codeEdt);

        final String token = FirebaseInstanceId.getInstance().getToken();
        Log.d("TAG", "instaneid.getinstance() :    "+token);

        gender.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup radioGroup, int i) {
                RadioButton genderBtn = (RadioButton)findViewById(R.id.genderWoman) ;
                boolean isChecked1 = genderBtn.isChecked();

                if(isChecked1 == true){
                    userGender = "여성";
                }else{
                    userGender = "남성";
                }
                Log.d("1 TAG  "+userGender,"  성별");
            }
        });

        //유치원 관계자 or 학부모 라디오그룹
        stateRG.setOnCheckedChangeListener((new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, @IdRes int k) {
                RadioButton stateKinder = (RadioButton)findViewById(R.id.stateKinder) ;
                LinearLayout CodeLayout = (LinearLayout) findViewById(R.id.codeLayout);

                //VISIBLE 애니매이션 효과
                Animation animationTrue = new AlphaAnimation(0, 1);
                animationTrue.setDuration(1000);

                boolean Checked = stateKinder.isChecked();

                if(Checked == true){
                    userState = "관계자";
                    stateValue = 1;
                    CodeLayout.setVisibility(View.VISIBLE);
                    CodeLayout.setAnimation(animationTrue);
                }else{
                    userState = "학부모";
                    stateValue = 2;
                    CodeLayout.setVisibility(View.INVISIBLE);
                }
                Log.d("1 TAG "+userState,"관계자 학부모");
            }
        }));

        validateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String userID = idText.getText().toString();
                if (validate) {
                    return;//검증 완료
                }

                //ID 값을 입력하지 않았다면
                if (userID.equals("")) {
                    AlertDialog.Builder builder1 = new AlertDialog.Builder(Signon.this);
                    dialog = builder1.setMessage("ID를 입력하세요.")
                            .setPositiveButton("OK", null)
                            .create();
                    dialog.show();
                    return;
                }


                //검증시작
                Response.Listener<String> responseListener = new Response.Listener<String>() {

                    @Override
                    public void onResponse(String response) {
                        try {
                            Toast.makeText(Signon.this, response, Toast.LENGTH_LONG).show();

                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success = jsonResponse.getBoolean("success");
                            if (success) {//사용할 수 있는 아이디라면
                                AlertDialog.Builder builder2 = new AlertDialog.Builder(Signon.this);
                                dialog = builder2.setMessage("사용 가능한 ID 입니다.")
                                        .setPositiveButton("OK", null)
                                        .create();
                                dialog.show();
                                idText.setEnabled(false);//아이디값을 바꿀 수 없도록 함
                                validate = true;//검증완료
                                idText.setBackgroundColor(getResources().getColor(R.color.colorPrimary));
                                validateButton.setBackgroundColor(getResources().getColor(R.color.colorPrimary));
                            } else {//사용할 수 없는 아이디라면
                                AlertDialog.Builder builder3 = new AlertDialog.Builder(Signon.this);
                                dialog = builder3.setMessage("사용중인 ID 입니다.")
                                        .setNegativeButton("OK", null)
                                        .create();
                                dialog.show();
                            }

                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                };//Response.Listener 완료

                //Volley 라이브러리를 이용해서 실제 서버와 통신을 구현하는 부분
                ValidateRequest validateRequest = new ValidateRequest(userID, responseListener);
                RequestQueue queue = Volley.newRequestQueue(Signon.this);
                queue.add(validateRequest);
            }
        });

        checkpasswordText.addTextChangedListener(new TextWatcher() {  //비밀번호 확인
            @Override
            public void beforeTextChanged(CharSequence charSequence, int start, int count, int after) {}
            @Override
            public void onTextChanged(CharSequence charSequence, int start, int before, int count) {
                if (passwordText.getText().toString().equals(checkpasswordText.getText().toString())) {
                    setImage.setImageResource(R.drawable.checked);
                }
                else {
                    setImage.setImageResource(R.drawable.unchecked);
                }
            }
            @Override
            public void afterTextChanged(Editable editable) {}
        });

        registerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d("TAG","토큰 : "+token);

                final String userID = idText.getText().toString();
                final String userPassword = passwordText.getText().toString();
                final String userName = nameText.getText().toString();
                final String userEmail = emailText.getText().toString();
                final String userCode = codeText.getText().toString();

                //ID 중복체크를 했는지 확인함
                if (!validate) {
                    AlertDialog.Builder builder4 = new AlertDialog.Builder(Signon.this);
                    dialog = builder4.setMessage("CHECK ID 버튼을 눌러주세요.")
                            .setNegativeButton("OK", null)
                            .create();
                    dialog.show();
                    return;
                }

                //빈칸 확인
                if (userID.equals("") || userPassword.equals("") || userName.equals("")){
                    AlertDialog.Builder builder5 = new AlertDialog.Builder(Signon.this);
                    dialog = builder5.setMessage("다시 확인하세요.")
                            .setNegativeButton("OK", null)
                            .create();
                    dialog.show();
                    return;
                }

                // ++ 유치원 코드 추가
                if(stateValue == 1 && userCode.equals("")) {
                    Log.d("userCode", "1");
                    AlertDialog.Builder builder6 = new AlertDialog.Builder(Signon.this);
                    dialog = builder6.setMessage("유치원 코드를 입력하세요.")
                            .setNegativeButton("OK", null)
                            .create();
                    dialog.show();
                    return;
                }

                if (!passwordText.getText().toString().equals(checkpasswordText.getText().toString())) {
                    AlertDialog.Builder builder7 = new AlertDialog.Builder(Signon.this);
                    dialog = builder7.setMessage("패스워드가 다릅니다.")
                            .setNegativeButton("OK", null)
                            .create();
                    dialog.show();
                    return;
                }




                //4. 콜백 처리부분(volley 사용을 위한 ResponseListener 구현 부분)
                Response.Listener<String> responseListener = new Response.Listener<String>() {

                    //서버로부터 여기서 데이터를 받음
                    @Override
                    public void onResponse(String response) {
                        try {
                            //서버로부터 받는 데이터는 JSON타입의 객체이다.
                            JSONObject jsonResponse = new JSONObject(response);
                            //그중 Key값이 "success"인 것을 가져온다.
                            boolean success = jsonResponse.getBoolean("success");

                            //회원 가입 성공시 success값이 true임
                            if (success) {
                                Toast.makeText(getApplicationContext(), "success", Toast.LENGTH_SHORT).show();

                                //알림상자를 만들어서 보여줌
                                AlertDialog.Builder builder8 = new AlertDialog.Builder(Signon.this);
                                dialog = builder8.setMessage("회원가입 성공")
                                        .setPositiveButton("확인", null)
                                        .create();
                                dialog.show();

                                //그리고 첫화면으로 돌아감
                                Intent intent = new Intent(Signon.this, Login.class);
                                finish();
                                Signon.this.startActivity(intent);

                            }

                            //회원 가입 실패시 success값이 false임
                            else {
                                Toast.makeText(getApplicationContext(), "fail", Toast.LENGTH_SHORT).show();

                                //알림상자를 만들어서 보여줌
                                AlertDialog.Builder builder = new AlertDialog.Builder(Signon.this);
                                builder.setMessage("register fail!!")
                                        .setNegativeButton("ok", null)
                                        .create()
                                        .show();
                            }
                        } catch (JSONException e) {
                            e.printStackTrace();
                        }

                    }
                };//responseListener 끝


                //volley 사용법
                //1. RequestObject를 생성한다. 이때 서버로부터 데이터를 받을 responseListener를 반드시 넘겨준다.
                SignonRequest registerRequest = new SignonRequest(
                        userName, userID, userPassword, userEmail,
                        userGender, userCode, userState, token, responseListener
                );

                Log.d("Request_TAG"+userState, "Request_TAG_관계자");
                //2. RequestQueue를 생성한다.
                RequestQueue queue = Volley.newRequestQueue(Signon.this);
                //3. RequestQueue에 RequestObject를 넘겨준다.
                queue.add(registerRequest);

            }
        });
    }

    @Override
    protected void onStop() {
        super.onStop();
        if (dialog != null) {
            dialog.dismiss();
            dialog = null;
        }
    }
}

