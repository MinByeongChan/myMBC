import java.util.*;

public class Solution_12909 {
    public static boolean solution(String s) {

        ArrayList<String> list = new ArrayList<String>();

        for (int i = 0; i < s.length(); i++) {
            String ss = String.valueOf(s.charAt(i));
            int LEN = list.size();

            if (list.size() == 0) {
                if (ss.equals(")")) {
                    return false;
                } else {
                    list.add(ss);
                    continue;
                }
            }

            if (list.get(LEN - 1).equals("(") && ss.equals(")")) {
                list.remove(LEN - 1);
            } else {
                list.add(ss);
            }
            // if (!list.get(LEN - 1).equals(ss)) {
            // System.out.println("POP");
            // list.remove(LEN - 1);
            // } else {
            // System.out.println("ADD");
            // list.add(ss);
            // }
        }

        if (list.size() == 0)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        String s = "()()";
        boolean result = solution(s);

        System.out.println("result " + result);
    }
}
