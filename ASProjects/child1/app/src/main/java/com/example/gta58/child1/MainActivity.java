package com.example.gta58.child1;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Toast;

/**
 * 네비게이션 드로어 적용
 *
 * @author
 * @version
 * @since
 * @created 2015. 9. 24.
 */


public class MainActivity extends AppCompatActivity {

    private final String[] navItems = {"버스 정보", "버스 위치", "비상 연락망"};
    private ListView lvNavList;
    private FrameLayout flContainer;
    private DrawerLayout dlDrawer;
    private ImageButton btn;

    @Override
    public void onBackPressed() {
        if (dlDrawer.isDrawerOpen(lvNavList)) {
            dlDrawer.closeDrawer(lvNavList);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lvNavList = (ListView)findViewById(R.id.lv_activity_main_nav_list);
        flContainer = (FrameLayout)findViewById(R.id.fl_activity_main_container);
        btn = (ImageButton)findViewById(R.id.btn);

        btn.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                Toast.makeText(getApplicationContext(), "open", Toast.LENGTH_SHORT).show();
                dlDrawer.openDrawer(lvNavList);
            }
        });

        dlDrawer = (DrawerLayout)findViewById(R.id.dl_activity_main_drawer);

        lvNavList.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, navItems));
        lvNavList.setOnItemClickListener(new DrawerItemClickListener());
    }

    private class DrawerItemClickListener implements ListView.OnItemClickListener {
        @Override
        public void onItemClick(AdapterView<?> adapter, View view, int position, long id) {
            switch (position) {
                case 0:
                    Intent intent1 = new Intent(
                            getApplicationContext(), // 현재 화면의 제어권자
                            Sub_info.class); // 다음 넘어갈 클래스 지정
                    startActivity(intent1); // 다음 화면으로 넘어간다
                    break;
                case 1:
                    Intent intent2 = new Intent(
                            getApplicationContext(), // 현재 화면의 제어권자
                            Sub_map.class); // 다음 넘어갈 클래스 지정
                    startActivity(intent2); // 다음 화면으로 넘어간다
                    break;

                case 2:
                    Intent intent3 = new Intent(
                            getApplicationContext(), // 현재 화면의 제어권자
                            Sub_call.class); // 다음 넘어갈 클래스 지정
                    startActivity(intent3); // 다음 화면으로 넘어간다
                    break;
            }
            dlDrawer.closeDrawer(lvNavList);
        }
    }
}