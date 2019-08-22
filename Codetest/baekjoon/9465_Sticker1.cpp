#include <iostream>
#define MAX 100001

using namespace std;

int score[2][MAX];
int direct[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };


//문제 잘못 이해해서 잘못 풀이한 함수
//배열 인덱스의 상,하,좌,우를 다 더해서 최대값 갱신하도록 구현
int stiker() {
	int max = 0, temp = 0;
	
	for(int p=0; p<2; p++) {
		for(int q=0; q<MAX; q++){
			if(score[p][q]== 0) break;
			temp = score[p][q];
			for(int i=0; i<4; i++){
				int nextY = p + direct[i][0];
				int nextX = q + direct[i][1];
				if(nextX<0 || nextY<0) continue;
				temp += score[nextY][nextX];
			}
			cout << temp << endl;
			if(max < temp) max = temp;
			temp = 0;
		}
	}
	return max;
}

int main(int argc, char** argv) {
	int T, n;// 테스트케이스 , 정수 갯수 
	
	cin >> T;
	cin >> n; 
	if(n<1 || n>100000) return 0;
	
	//입력 
	for(int t=0; t<T; t++) {
		cout << "success" << endl;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin >> score[i][j];
			}
		}
		// 함수 호출 및 출력 
		cout << stiker() << endl;
	}
	

	return 0;
}
