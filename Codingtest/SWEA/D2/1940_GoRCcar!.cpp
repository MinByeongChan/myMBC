#include <iostream>

using namespace std;


int main(int argc, char** argv) {
	int T; // 테스트 케이스 
	cin >> T;
	
	for(int t=1; t<=T; t++){
		int N;
		int distance=0; // 현재 거리 
		int v=0; // 속도 
		
		cin >> N; // 명령 수 
		
		for(int i=0; i<N; i++){
			int a, b;
			cin >> a;
			if(a==0) {
				distance += v;
				continue;
			}
			cin >> b;
			
			// 1이면 가속 
			if(a==1) v+=b;
			// 0이면 감속 
			if(a==2) v-=b;
			//현재 속도가 음수면 0으로 초기화 
			if(v <= 0) v=0; 
			//1명령당 결과를 현재거리에 누적 
			distance += v;
		}
		
		//1케이스당 1결과 출력 
		printf("#%d %d\n", t, distance);
		
	}

	return 0;
}
