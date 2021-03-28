import java.util.ArrayList;

public class Solution_12924 {
    public static int solution(int n) {
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = i; j <= n; j++) {
                sum += j;
                if (sum == n) {

                    cnt++;
                } else if (sum > n) {
                    break;
                }
            }
        }

        return cnt;
    }

    public static void main(String[] args) {
        int n = 15;
        int result = solution(n);

        System.out.println("result " + result);
    }
}
