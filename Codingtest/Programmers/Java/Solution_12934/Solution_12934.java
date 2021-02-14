package Java.Programmers.Solution_12934;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12934 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double answer = 0;

        long n = sc.nextLong();
        double x = Math.sqrt(n);
        if (n % x == 0) {
            System.out.println("True");
            answer = Math.pow(x + 1, 2);
        } else {
            System.out.println("False");
            answer = -1;
        }

        System.out.println((long) answer);
    }
}
