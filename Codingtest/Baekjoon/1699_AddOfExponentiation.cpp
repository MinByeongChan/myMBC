#include <iostream>
#define MAX 100001

using namespace std;

//sdad제곱 함수 
int EXPO(int a){
	return a*a;
}
//최솟값 함수 
int MIN(int a, int b){
	return a>b ? b : a;
}

int dp[MAX];

// 동전 2문제와 동일하게 접근 
int main(int argc, char** argv) {
	//변수 선언 
	int N; // 어떤 자연수 
	
	//INPUT
	cin >> N;
	if(N < 1) return -1;
	
	dp[0] = 0;
	for(int i=1; i<=N; i++){
		dp[i] = MAX;
	}
	
	for(int i=0; i<N/2; i++){
		for(int j=EXPO(i+1); j<=N; j++){
			dp[j] = MIN(dp[j], dp[j - EXPO(i+1)] + 1);
			cout << EXPO(i+1) << " : "<< dp[j] << endl;
		}
	}
	
	cout << dp[N];
	
	
	return 0;
}
