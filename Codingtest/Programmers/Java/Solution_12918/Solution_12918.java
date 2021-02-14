package Java.Programmers.Solution_12918;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12918 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        String strArr[] = new String[s.length()];
        for (int i = 0; i < s.length(); i++) {
            strArr[i] = s.substring(i, i + 1);
        }

        Arrays.sort(strArr, Collections.reverseOrder());

        String answer = "";
        for (int i = 0; i < strArr.length; i++) {
            answer += strArr[i];
        }

        System.out.println(answer);
    }
}
