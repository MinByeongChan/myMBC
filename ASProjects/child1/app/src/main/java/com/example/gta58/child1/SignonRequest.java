package com.example.gta58.child1;

/**
 * Created by gta58 on 2019-05-01.
 */

import com.android.volley.AuthFailureError;
import com.android.volley.Response;
import com.android.volley.toolbox.StringRequest;

import java.util.HashMap;
import java.util.Map;


public class SignonRequest extends StringRequest {

        final static private String URL = "http://13.124.166.248/Register_mbc2.php";
        private Map<String, String> parameters;

        //생성자
        public SignonRequest(String userName, String userID, String userPassword,
                             String userEmail, String userGender, String userCode,
                             String userState, String token, Response.Listener<String> listener) {
            super(Method.POST, URL, listener, null);

            parameters = new HashMap<>();
            //HashMap<String, String> parameters = new HashMap<String, String>();

            parameters.put("userName", userName);
            parameters.put("userID", userID);
            parameters.put("userPassword", userPassword);
            parameters.put("userEmail", userEmail);
            parameters.put("userGender", userGender);
            parameters.put("userCode", userCode);
            parameters.put("userState", userState);
            parameters.put("Token", token);

            System.out.println(parameters.values());
        }

    protected Map<String, String> getParams() throws AuthFailureError {
        return parameters;
    }
}