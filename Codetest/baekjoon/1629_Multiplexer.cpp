#include <iostream>

using namespace std;

//A : 곱하는 대상 
//B : 곱하는 횟수 
//C : 나눌 수 
long long A, B, C;
long long result = 1;

//곱셈 함수
//B를 반으로 쪼개서 계산
void Mul(long long b){
	if(b==0) {
		result*=result;//짝수면 결과의 제곱을 해서 출력
		//홀수면 결과의 제곱에서 A를 곱해서 출력
		if(B%2 != 0) {
			result = result * A;
		}
		//결과는 C로 나눈 나머지!
		//크기가 너무 크기 때문
		cout << result << endl;
		cout << result%C << endl;
		return ;
	}
	b--;
	result *=A;
	cout << result << endl;
	Mul(b);
}

int main(int argc, char** argv) {
	cin >> A >> B >> C;
	//범위 설절
	if(A < 0 || B < 0 || C <0) return 0;
	
	Mul(B/2);

	return 0;
}
