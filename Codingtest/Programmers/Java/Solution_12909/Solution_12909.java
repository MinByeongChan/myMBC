import java.util.*;

public class Solution_12909 {
    public static boolean solution(String s) {

        ArrayList<String> list = new ArrayList<String>();

        for (int i = 0; i < s.length(); i++) {
            String ss = String.valueOf(s.charAt(i));

            System.out.println("ss : " + ss);
            if (list.size() == 0) {
                System.out.println("ADD");
                list.add(ss);
                continue;
            } else {
                int LEN = list.size();

                if (list.get(LEN - 1) != ss) {
                    System.out.println("POP");
                    list.remove(LEN - 1);
                } else {
                    System.out.println("ADD");
                    list.add(ss);
                }
            }
        }

        if (list.size() == 0)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        String s = "(()(";
        boolean result = solution(s);

        String a = "asd";
        String b = a + "";
        System.out.println(a == b);

        System.out.println("result " + result);
    }
}
