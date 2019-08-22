#include <iostream>

using namespace std;

int n;
int arr[100];

//DP문제인지 모르고 그리디로 풀었음
//그리디로 풀면 풀어지는 범위가 한정되어있는듯 함
//점화식을 구해 풀어야하는 문제

// 카운트 갯수 초기화 
int expo(int exp){
	for(int i=0; i<n-1; i++){
		exp *= 2;
	}
	return exp;
}

//이진 생성 
int binary(int x){
	int p=0;
	if(x == 0) arr[p++] = 0;
	while(1){
		if(x == 1) {
			arr[p++] = 1;
			break;
		}
		arr[p++] = x % 2;
		x /= 2;
	}
	return 0;
}

int main(int argc, char** argv) {
	cin >> n;
	if(n>90 || n<1) return 0;
	
	fill(arr, arr+100, -1);
	
	int cnt = 1;
	cnt = expo(1);
	
	int i=cnt;
	while(1){
		binary(i);
		if(arr[n] != -1)  break;
		
		for(int p=1; p<n; p++){
			if(arr[n-1] == 0) break;
			if(arr[n-1] == 1){
				if(arr[p] == 1 && arr[p-1] == 1) {
					cnt--;
					break;
				}
			}
		}
		i++;
	}
	
	cout << cnt;

	return 0;
}
