package Java.Programmers.Solution_12933;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12933 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long answer = 0;

        String LEN = Long.toString(n);

        Long[] arr = new Long[LEN.length()];

        int cnt = 0;
        while (n != 0) {
            arr[cnt++] = (n % 10);
            n /= 10;
        }

        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");

        double d = 0;
        for (int i = 0; i < arr.length; i++) {
            d += arr[i] * Math.pow(10, i + 1);
        }
        System.out.println((long) d);

        // // arr = Arrays.stream(arr2).mapToInt(i -> i).toArray();
        // long answer = 0;
        // String answer2 = "";

        // for (int i = 0; i < 100; i++) {
        // if (arr2[i] == 0) {
        // break;
        // }
        // answer2 += arr2[i].toString();
        // }
        // System.out.println(Long.valueOf(answer2));
    }
}
