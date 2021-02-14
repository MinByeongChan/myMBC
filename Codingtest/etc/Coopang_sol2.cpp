#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


bool Check(int n, int m, int t, int k, int ii) {
	vector<int> arr;
	int sum = 0;

	while (ii != 0) {
		int x = ii % 10;
		if (x > k) return false;
		arr.push_back(x);
		sum += x;
		ii /= 10;
	}

	if (sum != m) return false;

	for (int i = 0; i < n; i++) {
		sum = 0;
		int idx = i;
		for (int j = 0; j < t; j++) {
			if (idx > arr.size() - 1) break;
			sum += arr[idx++];
		}
		if (sum > k) 
			return false;
	}
	return true;
}


int solution(int N, int M, int T, int K) {
	int answer = 0;

	for (int i = 0; i < pow(10, N); i++) {
		if (Check(N, M, T, K, i)) answer++;
	}

	return answer;
}
int main() {
	int n = 4;
	int m = 7;
	int t = 2;
	int k = 4;

	cout << solution(n, m, t, k) << endl;

	return 0;
}

