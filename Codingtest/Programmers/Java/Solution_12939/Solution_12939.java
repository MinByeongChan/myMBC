package Java.Programmers.Solution_12939;

import java.util.Scanner;

class Solution_12939 {

    public static String solution(String s) {
        String answer = "";

        String[] parts = s.split(" ");
        int mx = -10000000;
        int mn = 10000000;

        for (String ss : parts) {
            int a = Integer.parseInt(ss);
            if (mx < a)
                mx = a;
            if (mn > a)
                mn = a;
        }

        System.out.println("mx: " + mx);
        System.out.println("mn: " + mn);

        answer = String.valueOf(mn) + " " + String.valueOf(mx);

        return answer;
    }

    public static void main(String[] args) {
        String result = solution("-1 -2 -3 -4");
        System.out.println(result);
    }
}