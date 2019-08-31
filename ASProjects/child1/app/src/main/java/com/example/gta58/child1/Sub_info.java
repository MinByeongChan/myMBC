package com.example.gta58.child1;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;

import java.util.ArrayList;

public class Sub_info extends AppCompatActivity {
    Button button;
    private Spinner spinner2;
    ArrayList<String> arrayList;
    ArrayAdapter<String> arrayAdapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.info);

        arrayList = new ArrayList<>();
        arrayList.add("1호차");
        arrayList.add("2호차");
        arrayList.add("3호차");
        arrayList.add("4호차");
        arrayList.add("5호차");
        final String[] select_item = {""};



        arrayAdapter = new ArrayAdapter<>(getApplicationContext(),
                android.R.layout.simple_spinner_dropdown_item,
                arrayList);

        spinner2 = (Spinner)findViewById(R.id.spinner2);
        spinner2.setAdapter(arrayAdapter);
        spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
                select_item[0] = String.valueOf(arrayList.get(arg2));
            }

            @Override
            public void onNothingSelected(AdapterView<?> arg0) {

            }
        });




        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (select_item[0].equals("1반")) {
                    Intent intent = new Intent(Sub_info.this, One.class);
                    startActivity(intent);
                    finish();

                } else if (select_item[0].equals("2반")) {
                    Intent intent = new Intent(Sub_info.this, Two.class);
                    startActivity(intent);
                    finish();
                }
            }
        });


    }


}





