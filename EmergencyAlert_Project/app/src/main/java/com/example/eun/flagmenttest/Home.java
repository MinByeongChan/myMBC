package com.example.eun.flagmenttest;

import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import java.io.FileDescriptor;
import java.io.PrintWriter;


public class Home extends Fragment {
   // Button readyAlert,emerAlert;

    MainActivity activity ;
    DebugMode db = new DebugMode();


    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        activity = (MainActivity)getActivity();
    }

    @Override
    public void onDetach() {
        super.onDetach();
        db.r("Test","Home OnDetach");
        activity = null;
    }
    public void dump(String prefix, FileDescriptor fd, PrintWriter writer, String[] args) {
        super.dump(prefix, fd, writer, args);
    }

    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        ViewGroup rootView = (ViewGroup) inflater.inflate(R.layout.fragment_home,container,false );

        Button readyAlert = (Button) rootView.findViewById(R.id.readyAlert);
        Button emerAlert = (Button) rootView.findViewById(R.id.emerAlert);


        readyAlert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    activity.onStartService(1);
            }
        });
        emerAlert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    activity.onStartService(3);
            }
        });


        return rootView;
    }
}
