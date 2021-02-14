package Java.Programmers.Solution_12944;

public class Solution_12944 {
    public static void main(String[] args) {
        double answer = 0;
        int[] arr = { 1, 2, 3, 4 };

        for (int i = 0; i < arr.length; i++) {
            answer += arr[i];
        }

        System.out.println(answer / arr.length);

    }

}
