#include <iostream>

#define MAX 1000

using namespace std;

int a[MAX+1]; 

int Eureka(int a[], int n){
	return a[n+1] = a[n] + n+1;
}

//유레카 배열들의 합이 x가 맞으면 1 아니면 0 반환 
int Esolve(int n, int x, int p){
	int result = 0;
	for(int i=1; i<1000; i++){
		for(int j=1; j<1000; j++){
			for(int k=1; k<1000; k++){
				//세개의 값중 하나라도 x를 넘어가면 반복문 탈출
				if(a[i] >= x || a[j] >= x || a[k] >=  x) break;
				if(i < x && j < x && k < x){
					result = a[i] + a[j] + a[k];
					// 세개의 값이 x와 동일하면 1리턴
					if(result == x) {
						return 1;
					}
					//아니면 초기화 후 계속 반복
					else result = 0;
				}
			}
		}
	}
	//아무리 뒤져봐도 아니면 0 반환
	if(result != 1) return 0; 
}

int main(int argc, char** argv) {
	int n; // 테스트 케이스의 개수
	cin >> n;
	
	int d[3] = {0,}; //메모이제이션
	int *Enum = new int[n]; // 결과값(1,0)을 저장하는 배열 
	int x; // 예제 입력 	
	int p=0; // 삼각수의 합으로 표현되는 배열의 인덱스 
	
	a[1] = 1; // 첫째항 지정 
	//삼각형 수열 초기화 
	for(int i=1; i<MAX; i++){
		a[i+1] = Eureka(a, i);				
	}	
	
	//입력변수 x입력에 따른 Esolve함수 동작
	for(int i=0; i<n; i++){
		cin >> x;
		//입력변수에 대한 값 제한
		if(x<=1000 && x >= 3)
			Enum[i] = Esolve(n, x, i);
		else break;
	}

	//결과출력	
	for(int i=0; i<n; i++)
		cout << Enum[i] << endl;
	
	cin >> n;
	return 0;
}
