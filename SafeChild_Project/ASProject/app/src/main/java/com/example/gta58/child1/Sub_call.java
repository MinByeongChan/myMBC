package com.example.gta58.child1;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;


public class Sub_call extends AppCompatActivity {

    ImageButton call1;
    ImageButton call2;
    ImageButton call3;

    /**
     * Called when the activity is first created.
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.call);

        ImageButton call1 = (ImageButton) findViewById(R.id.call1);
        ImageButton call2 = (ImageButton) findViewById(R.id.call2);
        ImageButton call3 = (ImageButton) findViewById(R.id.call3);

        final String number1 = "01074754879";
        final String number2 = "01077020481";
        final String number3 = "01058925806";

        call1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent call_intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:" + number1));
                //You already have permission
                try {
                    startActivity(call_intent);
                } catch (SecurityException e) {
                    e.printStackTrace();
                }
            }
        });
        call2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent call_intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:"+number2));
                try {
                    startActivity(call_intent);
                } catch (SecurityException e) {
                    e.printStackTrace();
                }
            }
        });
        call3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent call_intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:"+number3));
                try {
                    startActivity(call_intent);
                } catch (SecurityException e) {
                    e.printStackTrace();
                }
            }
        });

    }

//        @Override
//        public void onClick(View arg0) {
//            switch (arg0.getId()) {
//
//                case R.id.call1:
//                    startActivity(new Intent("android.intent.action.CALL",
//                            Uri.parse("tel:01074754879")));
//                    break;
//
//                case R.id.call2:
//                    startActivity(new Intent("android.intent.action.DIAL",
//                            Uri.parse("tel:01063552515")));
//                    break;
//
//                case R.id.call3:
//                    startActivity(new Intent("android.intent.action.DIAL",
//                            Uri.parse("tel:01037624614")));
//                    break;
//            }
//        }
// }
}