#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];

int main() {
	int X, result = 0;
	cin >> X;
	
	fill(dp, dp + X+1, 0);
	dp[1] = 0;

	for (int i = 2; i <= X; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}


	cout << dp[X];

	cin >> X;

	return 0;
}