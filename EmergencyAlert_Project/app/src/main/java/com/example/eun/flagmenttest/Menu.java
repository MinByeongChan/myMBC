package com.example.eun.flagmenttest;

import android.content.Context;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;


public class Menu extends Fragment {

    public Menu() {

    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        Log.d("Test","Menu");
        View v = inflater.inflate(R.layout.fragment_menu, container, false);
        return v;
    }

}
