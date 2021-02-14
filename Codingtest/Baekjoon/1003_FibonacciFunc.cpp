#include <iostream>
using namespace std;

int dp1[41];
int dp2[41];

int fibo_0(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (dp1[x] != 0) return dp1[x];

	return dp1[x] = fibo_0(x - 1) + fibo_0(x - 2);
}

int fibo_1(int y) {
	if (y == 0) return 1;
	if (y == 1) return 0;
	if (y == 2) return 1;
	if (y == 3) return 1;
	if (dp2[y] != 0) return dp2[y];
	return dp2[y] = fibo_1(y - 1) + fibo_1(y - 2);
}

int main() {
	int t;
	cin >> t;

	fill(dp1, dp1 + 41, 0);
	fill(dp2, dp2 + 41, 0);


	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		cout << fibo_1(a) << " " << fibo_0(a) << "\n";
	}


	int n;
	cin >> n;

	return 0;
}