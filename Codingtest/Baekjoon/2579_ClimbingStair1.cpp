#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> stair;
vector<int> dp;
int N; // 계단의 개수

//int check(int start) {
//	int i = start, sum = 0;
//	vector<int> arr(stair);
//
//	while (i >= 0) {
//		if ((i - 2 >= 0) && arr[i - 1] >= arr[i - 2]) {
//			arr[i - 2] = 0;
//			i -= 2;
//		}
//		else if ((i - 2 >= 0) && arr[i - 1] < arr[i - 2]) {
//			arr[i - 1] = 0;
//			i -= 1;
//		}
//		i--;
//	}
//
//	for (int i = 0; i < N; i++)
//		sum += arr[i];
//
//	return sum;
//}
//
//int main() {
//	
//	int sum = 0;
//	cin >> N;
//
//	stair.resize(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> stair[i];
//	}
//
//	sum = check(N - 1);
//	
//	cout << sum;
//
//	cin >> N;
//	return 0;
//}


//int solution(int n, int sum) {
//	if (n < 0 ) return sum;
//	if (stair[n] == 0) solution(n - 1, sum);
//	sum += stair[n];
//	if ((n - 2 >= 0) && stair[n - 1] > stair[n - 2]) {
//		stair[n - 2] = 0;
//		solution(n - 1, sum);
//	}
//	else if((n - 2 >= 0) && stair[n - 1] <= stair[n - 2]) {
//		stair[n - 1] = 0;
//		solution(n - 2, sum);
//	}
//	else {
//		solution(n - 1, sum);
//	}
//}
//int main() {
//	cin >> N;
//	stair.resize(N);
//
//	for (int i = 0; i < N; i++)
//		cin >> stair[i];
//	vector<int> stair2(stair);
//	int sum1 = solution(N - 1, 0);
//
//	stair = stair2;
//
//	int sum2 = stair[N - 1] + stair[N - 2];
//	stair[N - 3] = 0;
//	sum2 += solution(N - 3, 0);
//
//	cout << sum1 << " / " << sum2 << '\n';
//
//	cin >> N;
//	return 0;
//}

int main() {
	cin >> N;
	stair.resize(N+2);
	dp.resize(N+2);

	for (int i = 1; i <= N; i++)
		cin >> stair[i];

	for (int i = 1; i <= 3; i	++) {
		if (i == 3)
			dp[i] = max(stair[i]+ stair[i-1], stair[i] + dp[i-2]);
		else {
			dp[i] = dp[i-1] + stair[i];
		}
	}

	for (int i = 4; i <= N; i++) {
		dp[i] = max(stair[i] + dp[i-2], stair[i] + stair[i-1] + dp[i-3]);
	}

	cout << dp[N];

	cin >> N;
	return 0;
}