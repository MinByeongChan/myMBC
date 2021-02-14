#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0, result = 0;

	for (int i = 0; i < N; i++) {
		sum += v[i];
		result += sum;
	}

	cout << result;

	cin >> N;
	return 0;
}