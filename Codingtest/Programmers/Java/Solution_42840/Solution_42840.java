import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Solution_42840 {
    public static int[] solution(int[] answers) {

        int supoja1[] = { 5, 1, 2, 3, 4 };
        int supoja2[] = { 5, 2, 1, 2, 3, 2, 4, 2 };
        int supoja3[] = { 5, 3, 3, 1, 1, 2, 2, 4, 4, 5 };
        int score[] = { 0, 0, 0 };
        int mx = 0;

        ArrayList<Integer> supojaAns = new ArrayList<Integer>();

        // int index = 0;
        // for (int i = 0; i < answers.length; i++) {
        // if (answers[i] == supoja1[index++]) {
        // score[0]++;
        // }
        // if (index == supoja1.length)
        // index = 0;
        // }

        // index = 0;
        // for (int i = 0; i < answers.length; i++) {
        // if (answers[i] == supoja2[index++]) {
        // score[1]++;
        // }
        // if (index == supoja2.length)
        // index = 0;
        // }

        // index = 0;
        // for (int i = 0; i < answers.length; i++) {
        // if (answers[i] == supoja3[index++]) {
        // score[2]++;
        // }
        // if (index == supoja3.length)
        // index = 0;
        // }

        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == supoja1[(i + 1) % 5])
                score[0]++;
            if (answers[i] == supoja2[(i + 1) % 8])
                score[1]++;
            if (answers[i] == supoja3[(i + 1) % 10])
                score[2]++;
        }

        for (int i = 0; i < score.length; i++) {
            System.out.println("score[" + i + "] " + score[i]);
            if (score[i] > mx)
                mx = score[i];
        }

        for (int i = 0; i < score.length; i++) {
            if (score[i] >= mx) {
                supojaAns.add(i + 1);
            }
        }

        return supojaAns.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        int answer[] = { 1, 2, 3, 4, 5 };
        // int answer[] = { 1, 3, 2, 4, 2 };

        int result[] = solution(answer);

        System.out.println("----------------------");
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
    }
}
