package Java.Programmers.Solution_12928;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12928 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> arrIntList = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                arrIntList.add(i);
            }
        }

        Integer answer = 0;

        for (Integer i : arrIntList) {
            System.out.println(i);
            answer += i;
        }

        System.out.println("answer : " + (int) answer);

    }
}
