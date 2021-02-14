#include <iostream>
#include <algorithm>
#define MAX_N 101
#define MAX_K 10001

using namespace std;

//변수 선언 
const int IMPOSSIBLE = 1000000;
int N ,K;
int coin[MAX_N];
int dp[MAX_N][MAX_K]; //각 케이스마다의 경우의 수를 등록 

//최소값 함수  
int MIN(int a, int b){
	return a > b ? b : a ;
}

int main(int argc, char** argv) {
	//입력 
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> coin[i];
	}
	
	//DP초기화
	//최솟값을 구하기 위해 매우 큰값을 집어넣음 
	for(int i=0; i<=N; i++){
		for(int j=1; j<=K; j++){
			dp[i][0] = 0;
			dp[i][j] = IMPOSSIBLE;
		}
	}
	
	//바텀업 방식 
	for(int i=0; i<=N; i++){
		dp[i][0] = 0;
		for(int j=coin[i]; j<=K; j++){
			dp[i+1][j] = MIN(dp[i][j], dp[i+1][j - coin[i]] +1);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	//답이 없을시 -1 
	if(dp[N][K] == IMPOSSIBLE) cout << "-1" << endl;
	//DP마지막 요소가 최적의 동전 개수 
	else cout << dp[N][K] << endl;
	
	
	return 0;
}
