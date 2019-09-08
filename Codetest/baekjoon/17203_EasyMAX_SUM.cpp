#include <iostream>

using namespace std;

//부분합 문제와 유사한 문제
//합을 그대로 더하는 대신 배열과 배열 사이의 차이값을
//nSum배열에 저장하고 똑같은 방식으로 진행 
int main(int argc, char** argv) {
	int N, Q, nSum[10001];
	int A = 0, B = 0;
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++){
		//홀짝 번갈아가며 입력 
		if(i%2!=0) {
			scanf("%d", &A);
		}
		else {
			scanf("%d", &B);
		}
		 
		if((B-A) < 0) nSum[i+1] = nSum[i] + (-1)*(B-A);
		else nSum[i+1] = nSum[i] + (B-A);
		
	}
	
	for(int i=0; i<Q; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		//차를 저장하는 방식을 하다보니 인덱스가 하나씩 밀림
		//결과와 상관없이 출력 됨  
		printf("%d\n", nSum[e] - nSum[s]);
	}

	return 0;
}
