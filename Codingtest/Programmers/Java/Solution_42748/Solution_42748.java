import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Solution_42748 {
    public static void main(String[] args) {
        int[] array = { 1, 5, 2, 6, 3, 7, 4 };
        int[][] commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
        int answer[] = new int[commands.length];

        for (int i = 0; i < commands.length; i++) {
            ArrayList<Integer> arrList = new ArrayList<Integer>();
            int start = commands[i][0] - 1;
            int end = commands[i][1] - 1;
            int index = commands[i][2] - 1;

            System.out.println("array[ " + i + " ]");

            for (int j = start; j <= end; j++) {
                arrList.add(array[j]);
            }

            Collections.sort(arrList);

            for (int j = 0; j < arrList.size(); j++) {
                System.out.print(arrList.get(j));
            }
            System.out.println("");

            answer[i] = arrList.get(index);
            System.out.println("answer : " + answer[i]);
        }

    }
}
