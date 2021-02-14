package Java.Programmers.Solution_12926;

import java.util.ArrayList;
import java.util.Scanner;

public class Solution_12926 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        // int n = 4;
        // String answer = "";

        // for (int i = 0; i < s.length(); i++) {
        // char c = s.charAt(i);
        // int nextChar;

        // if (c == ' ') {
        // answer += ' ';
        // } else {
        // if (65 <= c && c <= 90) {
        // nextChar = c + n > 90 ? (c + n - 90) + 64 : c + n;
        // } else {
        // nextChar = c + n > 122 ? (c + n - 122) + 96 : c + n;
        // }
        // answer += (char) nextChar;
        // }
        // }

        // System.out.println("answer : " + answer);

        String seoul[] = { "Jane", "Kim" };
        String answer = "";
        int index = 0;

        for (int i = 0; i < seoul.length; i++) {
            if (seoul[i] == "Kim") {
                break;
            }else {
                index++;
            }
        }
        answer = "김서방은 " + index + "에 있다";
        System.out.println("answer : " + answer);
    }
}
