#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int fibonacci(int n){
	if(n==1) return 1;
	if(n==2) return 1;
	if(n==3) return 2;
	if(dp[n] != -1) return dp[n];
	else return dp[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	dp.resize(n+1, -1);
	cout << fibonacci(n) << endl;	
	
	scanf("%d", n);
	return 0;
}
