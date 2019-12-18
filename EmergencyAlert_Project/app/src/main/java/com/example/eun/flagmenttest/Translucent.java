package com.example.eun.flagmenttest;

import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Vibrator;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class Translucent extends AppCompatActivity {
    View dialogView, toastView;
    CountDownTimer countDownTimer1;
    AlertDialog.Builder dlg;
    TextView dlgTextView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_translucent);
        Log.i("Test","Translucent");
        final Global global = (Global)getApplication();
        dialogView = (View) View.inflate(Translucent.this, R.layout.dialog, null);
        dlg = new AlertDialog.Builder(Translucent.this);
        dlg.setTitle("사용자 정보 입력");
        dlg.setView(dialogView);
        dlgTextView = (TextView) dialogView.findViewById(R.id.dialogTv);
        CountDown();

        dlg.setNegativeButton("취소", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface,int negativeBtn) {
                global.ChangeSafeDir(true);
                countDownTimer1.cancel();
                Translucent.this.finish();
            }
        });
        dlg.show();
    }
    public void CountDown() {
        final Global global = (Global)getApplication();
        countDownTimer1 = new CountDownTimer(5000, 1000) {
            @Override
            public void onTick(long l) {
                Log.i("Test","count"+l/1000);
                vibrator(500);
                dlgTextView.setText("카운트 다운 :  : " + l / 1000);
            }

            @Override
            public void onFinish() {
                global.ChangeSafeDir(false);
                countDownTimer1.cancel();
                Translucent.this.finish();
            }
        }.start();
    }
    public void vibrator(int v) {
        Vibrator vibrator = (Vibrator)getSystemService(Context.VIBRATOR_SERVICE);
        vibrator.vibrate(v);
    }
}
