import java.util.*;

public class BOJ_1449 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int answer = 1;

        int N = sc.nextInt();
        int L = sc.nextInt();
        int min = 1000;
        ArrayList<Integer> arr = new ArrayList<>();

        for(int i=0; i<N; i++) {
            int a = sc.nextInt();
            arr.add(a);
        }
        Collections.sort(arr);

        int pivot = arr.get(0);
        for(int i=1; i<N; i++) {
            if(pivot + L - 1 < arr.get(i)) {
                pivot = arr.get(i);
                answer++;
            }
        }

        System.out.println("answer "+answer);
    }
}
