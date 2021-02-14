package Java.Programmers.Solution_12947;

import java.util.Scanner;

public class Solution_12947 {

    public static void main(String[] args) {
        boolean answer = false;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int x = makeHarshard(n);

        if (n % x == 0) {
            answer = true;
        } else {
            answer = false;
        }

        System.out.println(answer);
    }

    public static int makeHarshard(int n) {
        int harshard = 0;

        while (n != 0) {
            harshard += (n % 10);
            n /= 10;
        }

        return harshard;
    }

}
