#include <cstdio>
#include <algorithm>
using namespace std;
 
int N, H[100000];
 
// 분할 정복으로 히스토그램 [s, e) 문제를 푸는 함수
int histogram(int s, int e){
    if(s == e) return 0; // base case: 넓이 0
    if(s+1 == e) return H[s]; // base case: 넓이 1
 
    int mid = (s+e)/2;
    int result = max(histogram(s, mid), histogram(mid, e)); // 각 양쪽 구간의 최댓값
 
    // 양쪽 구간에 걸쳐 있는 답을 O(e-s)에 찾음
    int w = 1, h = H[mid], l = mid, r = mid;
    while(r-l+1 < e-s){
        int p = l>s ? min(h, H[l-1]) : -1; // 왼쪽으로 확장했을 경우의 높이
        int q = r<e-1 ? min(h, H[r+1]) : -1; // 오른쪽으로 확장했을 경우의 높이
        // 더 높은(같은) 높이를 가진 쪽으로 확장
        if(p >= q){
            h = p;
            l--;
        }
        else{
            h = q;
            r++;
        }
        // 최댓값 갱신
        result = max(result, ++w*h);
    }
    return result;
}
 
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", H+i);
    printf("%d\n", histogram(0, N));
}

