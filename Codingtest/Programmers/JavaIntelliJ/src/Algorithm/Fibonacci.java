package Algorithm;

public class Fibonacci {
    static long dp[] = new long[10000];

    public static long fibonacci(int n) {
        if(n==1) return 1;
        if(n==2) return 1;
        if(n==3) return 2;
        if(dp[n] != 0) return dp[n];

        else return dp[n] = fibonacci(n-1) + fibonacci(n-2);
    }

    public static void main(String[] args) {
        int N = 50;

        long result = fibonacci(N);

        System.out.print("result "+result);
    }
}
