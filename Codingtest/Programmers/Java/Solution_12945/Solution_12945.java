package Java.Programmers.Solution_12969;

import java.util.Scanner;

class Solution_12945 {

    static int dp[] = new int[100001];

    public static int fibonacci(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 1;

        if (dp[n] != 0)
            return dp[n];

        return dp[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1234567;
    }

    public static int solution(int n) {

        return fibonacci(n);
    }

    public static void main(String[] args) {
        int result = solution(3);
        System.out.println(result);
    }
}