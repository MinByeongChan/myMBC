#include <iostream>

using namespace std;

long long int data[10000];

//DP문제인지 모르고 헤맨 문제
//점화식을 구해야한다는 걸 인지해야함 
long long int dp(long long int n){
	if(n==1) return 1;
	if(n==2) return 1;
	if(data[n] != -1) return data[n];
	
	return data[n] = dp(n-1) + dp(n-2);
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	if(n>90 || n<1) return 0;
	fill(data, data+10000, -1);
	
	cout << dp(n);
	
	return 0;
}
