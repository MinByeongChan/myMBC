#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int dp[MAX]; //메모이제이션

//Dynamic Programming 사용
int f(int n){
	if(n == 1) return 0;
	if(dp[n] != -1) return dp[n];
	
	int result = f(n-1) + 1;
	
	if(n%3 == 0) result = min(result, f(n/3) + 1);
	if(n%2 == 0) result = min(result, f(n/2) + 1);
	dp[n] = result;
	
	return result;
}

int main(int argc, char** argv) {
	int N;
	cin >> N;
	
	fill(dp, dp+MAX, -1);
	cout << f(N) << endl;

	return 0;
}
