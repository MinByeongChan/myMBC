#include<iostream>
using namespace std;

int main() {
	int arr[9], mx = 0, idx;
	fill(arr, arr + 9, 0);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		
		if (arr[i] > mx) {
			mx = arr[i];
			idx = i + 1;
		}
	}
	cout << mx << "\n";
	cout << idx;

	cin >> mx;

	return 0;
}