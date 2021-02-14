package Java.Programmers.Solution_12969;

import java.util.Scanner;

class Solution_12969 {
    public static void main(String[] args) {
        long[] answer = new long[1000];

        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            answer[i] = (long) (x * (i + 1));
            System.out.println(answer[i]);
        }

    }
}