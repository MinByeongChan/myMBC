import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution_42576 {

    public static String Solution(String[] participant, String[] completion) {
        ArrayList<String> p = new ArrayList<String>();
        for (String s : participant) {
            p.add(s);
        }
        Collections.sort(p);

        System.out.println("participant");
        for (String s : p) {
            System.out.print(s + " ");
        }
        System.out.println();

        ArrayList<String> c = new ArrayList<String>();
        for (String s : completion) {
            c.add(s);
        }
        Collections.sort(c);

        System.out.println("completion");
        for (String s : c) {
            System.out.print(s + " ");
        }
        System.out.println();
        System.out.println();

        String result = "";

        for (int i = 0; i < c.size(); i++) {
            if (!p.get(i).equals(c.get(i))) {
                result = p.get(i);
                break;
            }
        }
        if (result == "") {
            result = p.get(p.size() - 1);
        }

        // return p.get(p.size() - 1);
        return result;
    }

    public static void main(String[] args) {
        String answer = "";
        String participant[] = { "mislav", "stanko", "mislav", "ana" };
        String completion[] = { "stanko", "ana", "mislav" };
        // String participant[] = { "leo", "kiki", "eden" };
        // String completion[] = { "eden", "kiki" };
        // String participant[] = { "marina", "josipa", "nikola", "vinko", "filipa" };
        // String completion[] = { "josipa", "filipa", "marina", "nikola" };

        answer = Solution(participant, completion);

        // answer = p.get(p.size() - 1);

        // HashMap<String, String> map = new HashMap<String, String>();

        // for (String str : participant) {
        // map.put(str, str);
        // }

        // for (String str : completion) {
        // map.remove(str);
        // }

        // for (Map.Entry<String, String> entry : map.entrySet()) {
        // answer = entry.getValue();
        // }

        System.out.print("answer : " + answer);
    }
}
