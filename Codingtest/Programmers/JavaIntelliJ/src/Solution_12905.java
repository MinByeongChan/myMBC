/*
*  @ 프로그래머스 솔루션 12905
*  @ 1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다. 표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요. (단, 정사각형이란 축에 평행한 정사각형을 말합니다.)
* */
public class Solution_12905 {
    static int ROW_MAX = 0;
    static int COL_MAX = 0;

    public static int solution(int [][]board) {
        int MX = 0;
        COL_MAX = board[0].length;
        ROW_MAX = board.length;
        int[][] arr = new int[ROW_MAX+1][COL_MAX+1];

        // 입력값 출력
        for(int i=0; i<ROW_MAX; i++) {
            for(int j=0; j<COL_MAX; j++) {
                arr[i+1][j+1] = board[i][j];
                System.out.print(arr[i+1][j+1]+ " ");
            }
            System.out.println();
        }

        for(int i=1; i<=ROW_MAX; i++) {
            for(int j=1; j<=COL_MAX; j++) {
                if(arr[i][j] == 0) continue;

                int MN = Math.min(Math.min(arr[i][j-1], arr[i-1][j]), arr[i-1][j-1]);
                arr[i][j] = MN + 1;
                MX = Math.max(MX, arr[i][j]);
            }
        }

        System.out.println("--- ---");

        // 결과값 출력
        for(int i=0; i<ROW_MAX; i++) {
            for(int j=0; j<COL_MAX; j++) {
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }

        System.out.println("result "+MX*MX);

        return MX*MX;
    }

    public static void main(String[] args) {
//        int[][] board = {{0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,0,1,0}};
//        int[][] board = {{0,0,1,1}, {1,1,1,1}};
//        int[][] board = {{0,1}, {1, 0}};
        int[][] board = {{0,0}, {0, 0}};
        solution(board);
    }
}
