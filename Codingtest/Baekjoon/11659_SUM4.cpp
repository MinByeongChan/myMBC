#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int N, M, pSum[100001] = {0, };
	scanf("%d %d", &N, &M);
	//A�� �Է¹ް� ��ٷ� �迭�� ��pSum�� ���� 
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		pSum[i+1] = pSum[i] + A;
	}
	
	for(int i=0; i<M; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		//i~j������ ���� ��� 
		printf("%d\n", pSum[e] - pSum[s-1]);
	}

	return 0;
}
