package Java.Programmers.Solution_12930;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12930 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        String answer = "";
        s += " ";
        int S_LEN = s.length();
        StringBuffer result = new StringBuffer("");
        StringBuffer sb = new StringBuffer("");

        for (int i = 0; i < S_LEN; i++) {
            if (s.charAt(i) != ' ') {
                sb.append(s.charAt(i));
            } else {
                System.out.println("sb : " + sb.toString());
                int TMP_LEN = sb.length();

                for (int j = 0; j < TMP_LEN; j++) {
                    if (j % 2 == 0) {
                        sb.setCharAt(j, Character.toUpperCase(sb.charAt(j)));
                    } else {
                        sb.setCharAt(j, Character.toLowerCase(sb.charAt(j)));
                    }
                }

                result.append(sb.toString());
                result.append(" ");
                sb.delete(0, sb.length());
            }
        }

        result.delete(result.length() - 1, result.length());
        System.out.println(result.toString());

        // String[] arr = s.split(" ");

        // for (int i = 0; i < arr.length; i++) {
        // StringBuffer sb = new StringBuffer("");
        // for (int j = 0; j < arr[i].length(); j++) {
        // char c = arr[i].charAt(j);
        // if (j % 2 == 0) {
        // sb.append(Character.toUpperCase(c));
        // } else {
        // sb.append(Character.toLowerCase(c));
        // }
        // }
        // arr[i] = sb.toString();
        // }

        // StringBuffer sb2 = new StringBuffer("");
        // for (int i = 0; i < arr.length; i++) {
        // sb2.append(arr[i]);
        // sb2.append(" ");
        // }
        // sb2.delete(sb2.length() - 1, sb2.length());
        // System.out.println(sb2.toString());

    }
}
