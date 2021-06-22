import java.util.ArrayList;
import java.util.TreeSet;

/*
*  @ 프로그래머스 솔루션 77884
*  @ 두 정수 left와 right가 매개변수로 주어집니다. left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.
* */
public class Solution_77884 {

    public static boolean isEven(int num) {
        return num%2 == 0 ? true : false;
    }
    public static int getDivisorNum(int val) {
        int cnt = 1;
        for(int i=2; i<=val; i++) {
            if(val % i == 0)
                cnt++;
        }

        return cnt;
    }

    public static int solution(int left, int right) {
        int answer = 0;
        for(int i=left; i<=right; i++) {
            int num = getDivisorNum(i);
            if(isEven(num)) {   // 짝수
                answer += i;
            }else {             // 홀수
                answer -= i;
            }
        }
        System.out.println("answer : "+answer);

        return answer;
    }

    public static void main(String[] args) {
        int left=13, right=17;
        solution(left, right);
    }
}
