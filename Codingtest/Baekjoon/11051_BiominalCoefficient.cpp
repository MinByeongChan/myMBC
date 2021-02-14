#include <iostream>
#define MAX 1001
#define MOD 10007

using namespace std;

int N, K;
int dp[MAX][MAX];

//DP배열을 생성하여 모든 경우의 수에 대한 답을 효율적으로 저장
//점화식이 드릅게 어렵다 하... 
int Biominal(){
	//nCn, nC1, nC0에 대한 범위를 미리 초기화 
	for(int i=0; i<=N; i++){
		dp[i][1] = i;
		dp[i][0] = dp[i][i] = 1;
	}
	
	//3C2부터 nCk까지 차례대로 초기화
	//순서대로 저장되기 때문에 최종값인 5C3(예시)까지 찾을 수 있음  
	for(int i=3; i<=N; i++){
		for(int j=2; j<i; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
		}
	}
	return dp[N][K] % MOD;
}

int main(int argc, char** argv) {
	cin >> N>> K;
	
	cout << Biominal() << endl;
	
	return 0;
}
