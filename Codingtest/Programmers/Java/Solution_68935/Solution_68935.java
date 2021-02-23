import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Solution_68935 {
    public static void main(String[] args) {
        int answer = 0;
        int n = 45;
        String third = Integer.toString(n, 3);
        StringBuffer sb = new StringBuffer(third);
        String reversed = sb.reverse().toString();

        System.out.println(reversed);

        int exp = 0;
        for (int i = reversed.length() - 1; i >= 0; i--) {
            String str = "" + reversed.charAt(i);
            answer += Integer.parseInt(str) * Math.pow(3, exp++);
        }

        // 1번풀이
        String rest = "";
        // while (n != 0) {
        // int r = n % 3;
        // n /= 3;
        // rest += Integer.toString(r);
        // }

        // int index = rest.length() - 1;
        // for (int i = 0; i < rest.length(); i++) {
        // String str = "" + rest.charAt(i);

        // int num = Integer.parseInt(str);
        // answer += Math.pow(3, index--) * num;
        // }

        System.out.println("answer " + answer);
    }
}
