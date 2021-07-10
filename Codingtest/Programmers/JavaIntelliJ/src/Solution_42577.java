/*
*  @ 프로그래머스 솔루션 42577
*  @ 문제 : 전화번호 목록
*  @ 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
    전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

    구조대 : 119
    박준영 : 97 674 223
    지영석 : 11 9552 4421
    전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.
* */

import java.util.*;

public class Solution_42577 {
    static int LEN = 0;

    public static boolean solution(String[] phone_book) {
        LEN = phone_book.length;

        ArrayList<String> list = new ArrayList<String>();

        for(String str : phone_book) {
            list.add(str);
        }

        Collections.sort(list);

        for(int i=0; i<LEN-1; i++) {
            int minLen = Math.min(list.get(i).length(), list.get(i+1).length());

            String str1 = list.get(i).substring(0, minLen);
            String str2 = list.get(i+1).substring(0, minLen);

            if(str1.equals(str2)) return false;

        }

        return true;
    }

    public static void main(String[] args) {
//        String[] phone_book = {"119", "97674223", "1195524421"};
//        String[] phone_book = {"123", "456", "789"};
//        String[] phone_book = {"202", "12", "123", "1235", "567", "88", "123112321"};
        String[] phone_book = {"202", "1190", "2020"};

        boolean result = solution(phone_book);
        System.out.println("result "+ result);
    }
}
