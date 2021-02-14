#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, mx = 0;
	cin >> N;
	vector<int> lope(N);

	for (int i = 0; i < N; i++) {
		cin >> lope[i];
	}

	sort(lope.begin(), lope.end());

	for (int i = 0; i < N; i++) {
		int sum = lope[i] * (N - i);
		if (sum >= mx) {
			mx = sum;
		}
	}

	cout << mx;

	cin >> N;
	return 0;
}