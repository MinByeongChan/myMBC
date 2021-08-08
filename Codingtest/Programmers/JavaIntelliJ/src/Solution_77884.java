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

    public static class Solution_12951 {

        public static String solution(String s) {
    //        StringBuffer answer = new StringBuffer("");
            String answer = "";

            String[] strArr = s.split(" ");

            for(int i=0; i<strArr.length; i++) {
                for(int j=0; j<strArr[i].length(); j++ ){
                    char c = strArr[i].charAt(j);

                    if(j == 0) {
                        c = Character.toUpperCase(c);
                    }else {
                        c = Character.toLowerCase(c);
                    }
                    answer += c;
                }
                answer += " ";
            }



    //        for(int i=0; i<strArr.length; i++) {
    //            if(strArr[i].length() < 1) continue;
    //            String tmp = "";
    //            char c = strArr[i].charAt(0);
    //            if(97 <= c &&  c <= 122) {
    //                tmp += (char)( c - 32 );
    //                tmp += strArr[i].substring(1).toLowerCase(Locale.ROOT);
    //            } else {
    //                tmp += strArr[i].toLowerCase(Locale.ROOT);
    //            }
    //
    //            if(i != strArr.length - 1) tmp += " ";
    //
    //            answer.append(tmp);
    //        }

            return answer.substring(0, answer.length() - 1);
        }

        public static void main(String[] args) {
            String s = " 3people  unFollowed  me hey  ya ";
            //String s = "for the last week";
            String result = solution(s);
            System.out.println(result);
        }
    }
}
