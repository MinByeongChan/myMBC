#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> v;
int N;

void BinarySearch(int i, int sum) {
	if (i > N - 1)
		return ;

	int sum_temp = sum + v[i];

	/*if (sum_temp < dp[i])
		return;*/

	if (sum_temp >= dp[i]) {
		dp[i] = sum_temp;
		BinarySearch(i + 1, dp[i]);
	}
	if (sum_temp <= sum) {
		BinarySearch(i + 1, sum_temp);
	}
		
	
}

int main() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	dp = v;
	
	int sum = 0;
	/*
	int idx = 0;
	for (; idx < N; idx++) {
		if (v[idx] < 0) 
			break;
		sum += v[idx];
	}
	if (idx >= N) idx = N - 1;
	dp[idx] = sum;
	*/

	dp[0] = v[0];
	//BinarySearch(idx, sum);
	BinarySearch(0, 0);
	

	for (int i = 0; i < N; i++) {
		cout << "dp[" << i << "] : " << dp[i] << endl;
	}

	//최대값 구하기
	sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum <= dp[i])
			sum = dp[i];
	}
	cout << sum;

	cin >> N;
	return 0;
}