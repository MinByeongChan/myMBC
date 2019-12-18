#include <iostream>
#include <vector>
#include <algorithm>
//절대 나올수 없는 범위로 설정
#define INF 100001
using namespace std;

//배열 초기화  
vector<int> coin(101);
vector<int> dp(101, INF);
int N, K;

int main() {
    //INPUT
	cin >> N >> K;
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
            dp[j + 1] = min(dp[j + 1],  dp[j - coin[i]] + 1);
			//cout << dp[j] << endl;
		}
	}

	if (dp[K] == INF)
		cout << "-1";
	else
		cout << dp[K];

	return 0;
}
