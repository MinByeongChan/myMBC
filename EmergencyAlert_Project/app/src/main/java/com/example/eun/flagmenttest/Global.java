package com.example.eun.flagmenttest;

import android.app.Application;

public class Global extends Application {

    private boolean safe_dir=false;
    private boolean emer_timer_dir=true;

    public void ChangeSafeDir(boolean b) {
        safe_dir=b;
    }
    public  boolean getSafeDir() {
        return safe_dir;
    }
    public void ChangeEmerTimerDir(boolean b) {
        emer_timer_dir=b;
    }
    public boolean getEmerTimerDir() {
        return emer_timer_dir;
    }


}
