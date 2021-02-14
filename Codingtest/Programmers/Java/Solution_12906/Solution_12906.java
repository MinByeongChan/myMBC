import java.util.ArrayList;

public class Solution_12906 {
    public static void main(String[] args) {
        int arr[] = { 4, 4, 4, 3, 3 };

        ArrayList<Integer> arrList = new ArrayList<Integer>();
        arrList.add(arr[0]);

        for (int i : arr) {
            int lastIndex = arrList.size() - 1;
            if (i == arrList.get(lastIndex))
                continue;

            arrList.add(i);
        }

        int answer[] = arrList.stream().mapToInt(i -> i).toArray();

        for (int i : answer) {
            System.out.println(i);
        }

    }
}
