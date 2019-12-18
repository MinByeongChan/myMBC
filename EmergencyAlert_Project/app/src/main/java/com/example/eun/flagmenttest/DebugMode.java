package com.example.eun.flagmenttest;

import android.util.Log;

/**
 * Created by SEKYU on 2018-06-09.
 */

public class DebugMode {
    final boolean DEBUG = true;
    final public static int MAXCOUNT = 100*1000;// 신고 대기 카운트 다운
    final public static int M_PUSH = 3*20;//볼륨버튼 누르는 시간
    final public static long minTime = 3000;
    final public static float minDistance =1;




    public void r (String tag,String msg) {
        if(DEBUG) {
            Log.i(tag,msg);
        }
    }
}
