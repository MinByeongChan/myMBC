#include <iostream>

using namespace std;

//부분합
//부분배열의 합을 구하는 문제
//11659 합구하기4문제와 동일함
//매우 쉬움
//이 알고리즘은 꼭 알아두자 유용할듯 함 
int main(int argc, char** argv) {
	int N, M, nSum[100001] = {0, };
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		nSum[i+1] = nSum[i] + A;
	}
	
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", nSum[e]-nSum[s-1]);
	}

	return 0;
}
