package Java.Programmers.Solution_12912;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12912 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        long answer = 0;
        int gubunVal = 1;
        int start = b;
        int end = a;

        if (a < b) {
            start = a;
            end = b;
        }

        for (int i = start; i <= end; i += gubunVal) {
            answer += i;
        }

        System.out.print("answer : " + answer);
    }
}
