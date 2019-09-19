#include <iostream>

using namespace std;

int result[10] = {-1, };

void SheepCount(int x) {
	int temp = x;
//	cout << "SheepCount()" << endl;
	while(temp != 0) {
		int a = temp%10;
		if(result[a] == -1) {
			result[a] = 1;
//			printf("%d ", a);
		}
		temp/=10;
	}
//	cout << endl;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		result[10] = {-1, };
		cin >>N;
		
		//카운트마다 N의값을 더해갈 temp변수 
		int N_temp = N;
		
		//배열을 -1로 초기화 
		fill(result, result+10, -1);
		
		while(1) {
//			cout << "N : " << N << endl;
			//자리수 마다의 수를 배열에 저장
			//저장되는 값은 1로 설정
			//-1이면 아직 저장x, 1이면 저장 
			SheepCount(N);
			
			//반복문 탈출 조건 
			int exit = 0;
			for(int i=0; i<10; i++) 
				if(result[i] != -1) exit++;
			
			if(exit == 10) break; // 모든 개수가 다 세어질 때 exit 
			//아직 못구한 수가 있다면
			//N에 N을 더해간다. 
			else N += N_temp;
		}
		
		//xN번 곱한 N을 출력 
		cout << "#"<<t<< " "<< N << endl;
		
	}

	cin >> T;
	return 0;
}
