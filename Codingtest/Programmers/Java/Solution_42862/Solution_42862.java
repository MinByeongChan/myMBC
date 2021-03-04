import java.rmi.server.LogStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Solution_42862 {

    public static int solution(int n, int[] lost, int[] reserve) {
        int answer = n;

        for (int i = 0; i < lost.length; i++) {
            for (int j = 0; j < reserve.length; j++) {
                if (lost[i] == reserve[j]) {
                    lost[i] = -1;
                    reserve[j] = -1;
                    break;
                }
            }
        }

        for (int j = 0; j < reserve.length; j++) {
            System.out.print(reserve[j] + " ");
        }
        System.out.println();

        for (int i = 0; i < lost.length; i++) {
            if (lost[i] == -1)
                continue;
            int left = lost[i] - 1;
            int right = lost[i] + 1;
            boolean flag = false;

            for (int j = 0; j < reserve.length; j++) {
                if (reserve[j] == -1)
                    continue;

                if (reserve[j] == lost[i] || reserve[j] == left || reserve[j] == right) {
                    reserve[j] = -1;
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                answer--;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int n = 5;
        int lost[] = { 1, 2, 3 };
        int reserve[] = { 2, 3, 4 };
        // int lost[] = { 2, 4 };
        // int reserve[] = { 3 };
        // int lost[] = { 3 };
        // int reserve[] = { 1 };

        int result = solution(n, lost, reserve);

        System.out.println("----------------------");
        System.out.println(result);
    }
}
