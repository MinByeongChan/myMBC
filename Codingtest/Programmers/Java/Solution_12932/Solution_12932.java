package Java.Programmers.Solution_12932;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12932 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int LEN = Long.toString(n).length();

        System.out.println("LEN : " + LEN);
        int[] arr = new int[LEN];

        int i = 0;
        while (n != 0) {
            arr[i++] = (int) (n % 10);
            n /= 10;
        }

        for (int j = 0; j < arr.length; j++) {
            System.out.println(arr[j]);
        }

    }
}
