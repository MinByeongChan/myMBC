package Java.Programmers.Solution_12940;

import java.util.Scanner;

public class Solution_12940 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = n, b = m, p = 0;
        int dividor = 2;

        int[] arr = new int[1000000];

        while (true) {
            if ((dividor > n) || (dividor > m)) {
                break;
            }

            if ((a % dividor == 0) && (b % dividor == 0)) {
                arr[p++] = dividor;
                a /= dividor;
                b /= dividor;
            } else
                dividor++;
        }

        int result1 = 1;
        int result2 = 1;

        for (int i = 0; i <= p; i++) {
            if (arr[i] != 0) {
                result1 *= arr[i];
            }
        }

        System.out.println("result1 : " + result1);
        result2 = result1 * a * b;
        System.out.println("result1 : " + result2);
    }

}
