#include <iostream>

using namespace std;


int N, M;
int arr[16][16] = {0,};

// 오류찾느라 시간 꽤 걸렸던 문제 하... 
int Sum(int x, int y) {
	int sum = 0;
	//더하는 범위가 N보다 커질 경우 0반환  
	if(x+M > N || y+M > N) return 0;
	for(int i=y; i<y+M; i++){
		for(int j=x; j<x+M; j++) {
			//파리채 크기만큼 합을 구함  
			sum += arr[j][i];
		}
	}
	
	return sum;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int result=0;
		int max = 0;
		// N : 배열 영역, M : 파리채 크기
		cin >> N >> M;
		
		//NxN배열 초기화 
		for(int i=0; i<16; i++) {
			fill(arr[i], arr[i]+16, 0);
		}
		
		//NxN배열 영역 입력 
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				cin >> arr[j][i];
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				result = Sum(j, i);
				//최대값 구하기  
				if(result > max ) max = result;
			}
		}
		//OUTPUT 
		cout << "#" << t << " "<< max <<endl;
		 
	}
	
	
	return 0;
}
