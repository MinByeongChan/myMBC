#include <iostream>
#include <vector>

using namespace std;

int a[10001];

//생성자 만드는 함수d
int d(int x){
	int result = 0;
	int temp = x; // x에 대한 임시변수

	if(x < 10000){
		while(1){
			if(temp > 0){
				result += (temp % 10);
				temp /=10;
			}
			else break;
		}
		return result + x; // 자리수의 합과 자기자신의 합을 리턴
	}
}

int main(int argc, char** argv) {	
	for(int i=0; i<10001; i++){
		a[d(i)] = 1;//생성자가 있을 시 각 배열에 1을 대입
		if(a[i]!= 1) cout << i << ' '; // 배열중 1이 아닌 인덱스를 모두 출력
	}
	return 0;
}
