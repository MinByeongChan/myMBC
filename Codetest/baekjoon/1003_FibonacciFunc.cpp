#include <iostream>

using namespace std;

int n, T, cnt_0, cnt_1;
int dp[40];

int fibonacci(int n) {
    if (n == 0) {
        cnt_0++;
        return 0;
    } else if (n == 1) {
        cnt_1++;
        return 1;
    }
	if(dp[n] != 0 )
		return dp[n];
	else {
        return dp[n] = fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(int argc, char** argv) {	
	cin >> T;
	
	for(int t=0; t<T; t++) {
		cin >> n;
		cnt_1 = 0;
		cnt_0 = 0;
		fill(dp, dp+40, 0);
		
		cout <<fibonacci(n) << "\n";
		
		cout << cnt_0 << " " << cnt_1 << "\n";
	}
	

	cin >> T;

	return 0;
}
