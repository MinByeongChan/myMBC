#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> stair;
vector<int> dp;
int N; // 계단의 개수

int solution(int n, int sum) {
	if (n < 0 ) return sum;
	if (stair[n] == 0) solution(n - 1, sum);
	sum += stair[n];
	if ((n - 2 >= 0) && stair[n - 1] > stair[n - 2]) {
		stair[n - 2] = 0;
		solution(n - 1, sum);
	}
	else if((n - 2 >= 0) && stair[n - 1] <= stair[n - 2]) {
		stair[n - 1] = 0;
		solution(n - 2, sum);
	}
	else {
		solution(n - 1, sum);
	}
}

int main() {
	cin >> N;
	stair.resize(N);

	for (int i = 0; i < N; i++)
		cin >> stair[i];
	vector<int> stair2(stair);
	int sum1 = solution(N - 1, 0);

	stair = stair2;

	int sum2 = stair[N - 1] + stair[N - 2];
	stair[N - 3] = 0;
	sum2 += solution(N - 3, 0);

	cout << sum1 << " / " << sum2 << '\n';

	cin >> N;
	return 0;
}