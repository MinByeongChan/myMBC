#include <iostream>

using namespace std;

//각 케이스마다으 합에 대한 최대값 반환 함수
int MAX(int t[]){
	int max = 0;
	for(int i=0; i<10001; i++){
		if(t[i] != 0){
			if(max <= t[i]) max = t[i];
		}
	}
	return max;
}

int main(int argc, char** argv) {
	int n; //n개의 정수로 이루어진 수열
	scanf("%d", &n);

	int *a = new int[n]; // 동적으로 배열 생성
	int temp[10001] = {0,}; // 각 항들을 초기화
	int result = 0;
	int x;
	
	//항이 n개인 수열 생성	
	for(int i=0; i<n; i++){
		a[i] = 0;
		scanf("%d", &a[i]);
	}
	
	for(int j=1; j<n-1; j++){
		int k=0;
		int p=j;
		for(int i=0; i<n-1; i++){
			if(i >= n-j) break; // i값을 제한하기 위함 
			for(int k=i; k<=p; k++){
				temp[x] += a[k];
			}
			p++;
			x++;
		}
	}
	
	printf("%d\n", MAX(temp));
	
	x=0;
	
	//각 케이스마다 저장되어있는 값들을 출력
	for(int i=0; i<10001; i++){
		if(temp[i] != 0) printf("%d : %d\n", i+1, temp[i]);
	}
	
	scanf("%d", &n);
	
	delete[] a;
	
	return 0;
}
