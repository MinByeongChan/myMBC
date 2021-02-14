#include <iostream>
#include <vector>
using namespace std;

int N;
long long int S;
int mn = 0;
vector<int> v;

bool Check() {
	long long int sum = 0;
	for (int i = 0; i < N; i++) 
		sum += v[i];
	
	if (S <= sum) 
		mn = N;
	else {
		cout << '0';
		return false;
	}

	return true;
}

void CheckMid(int left, int right, bool flag) {
	if (left < 0) return;
	if (right > N - 1) return;

	//cout << "left: " << left << " / right: " << right << "\n";

	long long int sum = 0;
	int len = (right - left) + 1;

	for (int i = left; i <= right; i++)
		sum += v[i];

	if (sum >= S) {
		if (mn > len) {
			mn = len;
		}
		return ;
	}
		

	if (!flag)
		CheckMid(left - 1, right, true);
	else
		CheckMid(left, right + 1, false);
}

void BinarySearch(int left, int right) {
	if (left >= right) return ;
	//cout << "left: " << left << " / right: " << right << "\n";
	int mid = (left + right) / 2;
	long long int sum = 0;
	int len = (right - left) + 1;

	for (int i = left; i <= right; i++) 
		sum += v[i];

	if (sum >= S && mn > len) 
		mn= len;

	if (sum < S)
		return ;
	
	//cout << "sum: " << sum << " / LEN: " << len << "\n";

	BinarySearch(left, mid);
	BinarySearch(mid+1, right);
}

int main() {
	cin >> N >> S;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	//initialize mn
	if (!Check())
		return 0;

	int mid = (N - 1) / 2;
	CheckMid(mid, mid+1, true);

	BinarySearch(0, N-1);

	cout << mn;

	return 0;
}