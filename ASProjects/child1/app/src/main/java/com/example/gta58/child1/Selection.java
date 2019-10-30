package com.example.gta58.child1;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageButton;


public class Selection extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_selection);

        final ImageButton ImageButton1 = (ImageButton) findViewById(R.id.first_busBt);
        final ImageButton ImageButton2 = (ImageButton) findViewById(R.id.second_busBt);
        final ImageButton ImageButton3 = (ImageButton) findViewById(R.id.third_busBt);

        ImageButton1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent_map = new Intent(Selection.this, MainActivity.class);
                startActivity(intent_map);
            }
        });


        ImageButton2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent_info = new Intent(Selection.this, MainActivity.class);
                startActivity(intent_info);
            }
        });


        ImageButton3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent_call = new Intent(Selection.this, MainActivity.class);
                startActivity(intent_call);
            }
        });
    }}