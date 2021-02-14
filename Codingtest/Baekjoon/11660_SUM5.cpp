#include <cstdio>
using namespace std;
 
int main(){
    // 입력받으면서 prefix sum을 채움(행, 열 1칸씩 더 필요함에 유의)
    int N, M, pSum[1025][1025];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int A;
            scanf("%d", &A);
            pSum[i+1][j+1] = pSum[i+1][j] + pSum[i][j+1] - pSum[i][j] + A;
        }
    }
 
    // 각 쿼리를 처리
    for(int i = 0; i < M; ++i){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", pSum[x2][y2] - pSum[x1-1][y2] - pSum[x2][y1-1] + pSum[x1-1][y1-1]);
    }
}
