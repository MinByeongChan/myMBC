#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int N;
vector<int> arr;
vector<int> dp;

int main() {
	cin >> N;
	arr.resize(N);
	dp.resize(N + 1, 0);
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	//dp[0] 초기화
	dp[0] = arr[0];
	int mx = arr[0]; // 최대값
	int pivot = 0;

	
	//for (int k = 0; k < N-1; k++) {
	//	pivot = k;

	//	for (int i = pivot+1; i < N; i++) {

	//		if (arr[i] > arr[i - 1]) {
	//			dp[i] = max(dp[i - 1] + arr[i], dp[pivot] + arr[i]);
	//			//dp[i] = dp[i - 1] + arr[i];
	//		}

	//		else {
	//			if (arr[i] > arr[pivot]) {
	//				dp[i] = dp[pivot] + arr[i];
	//				pivot = i;

	//			}
	//			else {
	//				dp[i] = arr[i];
	//			}

	//		}

	//		//최대값 갱신
	//		if (dp[i] > mx) {
	//			mx = dp[i];
	//		}


	//	}
	//}
	

	for (int i = 0; i < N-1; i++) {
		pivot = i;
		for (int j = i+1; j < N; j++) {
			if (arr[j] > arr[j-1] && arr[j] > arr[pivot]) {
				int sum = arr[j] + dp[pivot];
				if (sum >= dp[j]) {
					dp[j] = sum;
				}
				else {
					break;
				}
				pivot = j;
			}
			else {
				dp[j] = arr[j];
				continue;
			}
			//최대값 갱신
			if (dp[j] > mx) {
				mx = dp[j];
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << dp[i] << " ";
	cout << "\n";


	cout << mx;
	cin >> N;

	return 0;
}