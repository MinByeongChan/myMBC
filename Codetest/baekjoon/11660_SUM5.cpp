#include <cstdio>
using namespace std;
 
int main(){
    // �Է¹����鼭 prefix sum�� ä��(��, �� 1ĭ�� �� �ʿ��Կ� ����)
    int N, M, pSum[1025][1025];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int A;
            scanf("%d", &A);
            pSum[i+1][j+1] = pSum[i+1][j] + pSum[i][j+1] - pSum[i][j] + A;
        }
    }
 
    // �� ������ ó��
    for(int i = 0; i < M; ++i){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", pSum[x2][y2] - pSum[x1-1][y2] - pSum[x2][y1-1] + pSum[x1-1][y1-1]);
    }
}
