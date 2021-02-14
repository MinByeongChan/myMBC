#include <iostream>
#include<vector>
#define MAX 101
using namespace std;

vector<long long int> dp(MAX);
vector<long long int> result;

long long int padoban(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (x == 3) return 1;
	if (x == 4) return 2;
	if (x == 5) return 2;

	if (dp[x] != 0) return dp[x];
	
	return dp[x] = padoban(x - 1) + padoban(x - 5);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int N;
		cin >> N;

		fill(dp.begin(), dp.end(), 0);

		result.push_back(padoban(N));
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << "\n";
	}
	
	cin >> t;

	return 0;
}