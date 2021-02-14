package Java.Programmers.Solution_12921;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12921 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean arr[] = new boolean[n + 1];

        for (int i = 2; i <= n; i++) {
            if (arr[i] == true) {
                continue;
            }

            for (int j = i + i; j <= n; j += i) {
                arr[j] = true;
            }
        }

        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (arr[i] == false) {
                cnt++;
            }
        }

        System.out.println("cnt : " + cnt);
    }
}
