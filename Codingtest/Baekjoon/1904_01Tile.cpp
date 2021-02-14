#include <iostream>

#define MAX 10000001

using namespace std;

int data[MAX];

//가장 기초적인 DP 문제 
//점화식 알면 끝나는 문제 
int dp(int x){
	if(x == 1) return 1;
	if(x == 2) return 2;
	//메모이제이션 
	if(data[x] != 0) return data[x] % 15746;
	data[x] = dp(x-1) + dp(x-2);
	return data[x] % 15746;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	//n의 범위 설정 
	if(n<1 || n > MAX) return 0;
	//출력 
	cout << dp(n);
	
	return 0;
}
