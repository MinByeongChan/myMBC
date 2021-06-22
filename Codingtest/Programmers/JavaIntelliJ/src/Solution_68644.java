import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Stream;

public class Solution_68644 {
    public static int[] solution(int[] numbers) {
//        int[] answer = new int[10000];
        ArrayList<Integer> answer = new ArrayList<Integer>();
        int NUM_LEN = numbers.length;
        TreeSet<Integer> ts = new TreeSet<Integer>();

        for(int i=0; i<NUM_LEN; i++) {
            for(int j=i+1; j<NUM_LEN; j++) {
                ts.add(numbers[i]+numbers[j]);
            }
        }

        for(Integer i : ts) {
            answer.add(i);
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        int[] nums = {2,1,3,4,1};

        int[] result = solution(nums);

        System.out.println("- result -");
        for (int data: result
             ) {
            System.out.println(data);
        }
    }
}
