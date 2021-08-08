import java.util.Scanner;

public class BOJ_4796 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int answer = 0;
        int L = sc.nextInt();
        int P = sc.nextInt();
        int V = sc.nextInt();

        while(true) {
            if(V < P) break;
            answer += L;
            V -= P;
        }

        if(V <= L) answer += V;

        System.out.println("answer "+ answer);


    }
}
