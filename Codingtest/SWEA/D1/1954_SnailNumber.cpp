#include <iostream>

#define MAX 51
using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++){
		int N, snum=1;
		int dir = 1;
		int arr[MAX][MAX] = {0, };
		cin >> N;
		
		int NN = N; // NN은 출력하기 위한 변수 
		
		printf("#%d\n", t);
		
		int i=0, j = -1;
		while(N > 0){
				for(int k=0; k<N; k++) {
					//방향의 의미인 dir을 따로 
					//선언하여 매번 더해줌 
					j += dir;
					arr[i][j] = snum++;
				}
				N--;
				for(int k=0; k<N; k++) {
					i += dir;
					arr[i][j] = snum++;
				}
			//방향을 바꾸어서 다시 진행 
			dir*=-1;
		} 
		//OUTPUT
		for(int i=0; i<NN; i++){
			for(int j=0; j<NN; j++){
				cout << arr[i][j]<< " " ;
			}
			cout << endl;
		}
	}
	
	cin >> T;

	return 0;
}
