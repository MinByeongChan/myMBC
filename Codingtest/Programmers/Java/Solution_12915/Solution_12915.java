package Java.Programmers.Solution_12915;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class CustomComparator implements Comparator<String> {
    private int n = 0;

    public CustomComparator(int n1) {
        this.n = n1;
    }

    @Override
    public int compare(String s1, String s2) {
        String str1 = s1.substring(n, s1.length());
        String str2 = s2.substring(n, s2.length());
        return 1;
    }
}

public class Solution_12915 {

    public static void main(String[] args) {
        // String strings[] = { "sun", "bed", "car" };
        String strings[] = { "zaa", "aab", "aaa" };
        int n = 1;
        ArrayList<String> strList = new ArrayList<String>();

        for (int i = 0; i < strings.length; i++) {
            strList.add(strings[i]);
        }

        Collections.sort(strList, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                if (s1.charAt(n) == s2.charAt(n)) {
                    return s1.compareTo(s2);
                }

                String str1 = s1.substring(n, s1.length());
                String str2 = s2.substring(n, s2.length());

                return str1.compareTo(str2);
            }

        });

        String answer[] = new String[strList.size()];
        for (int i = 0; i < strList.size(); i++) {
            answer[i] = strList.get(i);
        }

        for (int i = 0; i < answer.length; i++) {
            System.out.println(answer[i]);
        }
    }
}
