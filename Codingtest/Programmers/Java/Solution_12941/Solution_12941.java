import java.util.*;

class Solution_12941 {

    public static int solution(int[] A, int[] B) {
        int answer = 0;

        ArrayList<Integer> AList = new ArrayList<Integer>();
        ArrayList<Integer> BList = new ArrayList<Integer>();
        for (int i : A) {
            AList.add(i);
        }
        System.out.println();

        Collections.sort(AList);

        for (int i : B) {
            BList.add(i);
        }
        System.out.println();

        Collections.sort(BList, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                // TODO Auto-generated method stub
                return o2.compareTo(o1);
            }
        });

        for (int i : AList) {
            System.out.print(i + " ");
        }
        System.out.println();

        for (int i : BList) {
            System.out.print(i + " ");
        }
        System.out.println();

        // int result[] = new int[AList.size()];
        for (int i = 0; i < AList.size(); i++) {
            answer += (AList.get(i) * BList.get(i));
        }

        return answer;
    }

    public static void main(String[] args) {
        int A[] = { 1, 2 };
        int B[] = { 3, 4 };

        int result = solution(A, B);
        System.out.println("result : " + result);
    }
}