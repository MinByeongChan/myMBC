package Algorithm;

import java.util.Scanner;

public class BOJ_2805 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] treeHeight = new int[1000000];
        for(int i=0; i<N; i++) {
            treeHeight[i] = sc.nextInt();
        }

        int lo = 0;
        int hi = 1000000000;

        while(lo+1 < hi) {
            int mid = (lo + hi) / 2;
            long sum = 0;

            for(int i=0; i<N; i++) {
                if(treeHeight[i] > mid)
                    sum += (treeHeight[i] - mid);
            }

            if(sum >= M) lo = mid;
            else hi = mid;
        }

        System.out.println("result " + lo);
    }
}
