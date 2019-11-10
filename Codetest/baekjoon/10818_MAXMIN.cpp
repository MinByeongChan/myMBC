#include <iostream>
#define MAX 1000000
using namespace std;


int main() {
	int n, mx = -1000000, mn = MAX, a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > mx)
			mx = a;
		if (a < mn)
			mn = a;
	}
	cout << mn << " " << mx;

	cin >> n;

	return 0;
}