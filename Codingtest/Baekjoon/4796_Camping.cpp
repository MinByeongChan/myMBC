#include <iostream>
#define MAX 100

using namespace std;

int main(int argc, char** argv) {
	int P[MAX]; // 연속하는 P일중에 
	int L[MAX]; // L일만 캠핑장을 사용할 수 있다 
	int V[MAX]; // 강산이의 휴가	
	
	int result[MAX] = {0,};
	
	int i=0; // 입력 갯수
	while(1){
		cin >> L[i] >> P[i] >> V[i] ; // 입력 
		if(L[i] == 0 && P[i] == 0 && V[i] == 0) break;
		i++;
	}
	
	for(int j=0; j<MAX; j++){
		if(L[j]==0 && P[j]==0 && V[j]==0) break;
		while(1){
			//휴가 일수가 캠핑장에 연속으로 갈수있는 최대 수를 뺌
			if(V[j] >= P[j]) {
				V[j]-=P[j];
				result[j] += L[j];
			}
			//반복으로 빼고 남아있는 것들을 result에 합산시킴
			else {
				if(V[j] >= L[j]) result[j] += L[j];
				if(V[j] < L[j]) result[j] += V[j];
				break;
			}
		}
	}
		
	//입력갯수만큼 출력
	for(int j=0; j<MAX; j++){
		if(result[j] != 0)
			printf("Case %d: %d\n", j+1, result[j]);
		else break;
	}

	return 0;
}
