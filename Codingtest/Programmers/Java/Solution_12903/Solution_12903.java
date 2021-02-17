import java.util.ArrayList;

public class Solution_12903 {
    public static void main(String[] args) {
        String s = "abcde";
        // String s = "qwer";
        int S_LEN = s.length();
        String answer = "";
        int index = S_LEN / 2;

        if (S_LEN % 2 == 0) {
            answer = s.substring(index - 1, index + 1);
        } else {
            answer = s.substring(index, index + 1);
        }

        System.out.println("answer : " + answer);
    }
}
