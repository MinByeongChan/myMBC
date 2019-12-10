#include <iostream>
#include <vector>
using namespace std;

// variable init
vector<long long int> dp;
vector<long long int> v;
int N;
long long int mx = -1000;

/*
스택오버플로우로 인한 실패
N이 5000이상이면 스택이 쌓여 도중에 중단됨.
*/
void BinarySearch1(int i, long long int sum) {

	long long int sum_temp = sum + v[i];

	if (sum_temp < dp[i])
		return;
	
	// Update dp[i](max value)
	if (sum_temp > dp[i]) 
		dp[i] = sum_temp;

	// Searching for max value
	if (dp[i] > mx)
		mx = dp[i];
	
	if (i > N - 2)
		return;

	BinarySearch1(i + 1, dp[i]);

	if (v[i + 1] < 0 && i < N-3)
		BinarySearch1(i + 2, 0);	
}

int main() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];
	

	// duplicate Input vector
	dp = v;


	//Binary search
	//BinarySearch(0, 0);
	
	if (dp[0] > mx)
		mx = dp[0];

	for (int i = 1; i < N; i++) {

		if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
			dp[i] += dp[i - 1];
		}
		//cout << "dp[" << i << "] : " << dp[i] << endl;

		if (mx < dp[i])
			mx = dp[i];
	}

	cout << mx;

	cin >> N;
	return 0;
}

