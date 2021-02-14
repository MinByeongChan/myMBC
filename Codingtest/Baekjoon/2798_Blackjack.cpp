#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, mx = 0;
	int arr[101];
	int sum = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum > M) break;
				if (sum >= mx) mx = sum;
				sum = 0;
			}
		}
		
	}
	cout << mx;

	cin >> N;
	return 0;
}