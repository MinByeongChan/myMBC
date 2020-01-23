#include<iostream>
#include <string>
#include <vector>
using namespace std;

int answer = 0;

// 재귀함수로 구현
// i는 다음 인덱스, sum은 나열된 array의 합
void Check(int n, int i, int sum) {
	if (sum == n) { // n과 같아지면 answer 증가 후 리턴
		answer++;
		return ;
	}
	
	int next = i + 1;
	if (next >= n) // n 제한조건
		return ;

	if (sum + next > n) // sum이 n을 초과하게 되어도 return
		return ;
	else  // next를 넘겨주어 재귀함수 진행시킴
		Check(n, next, sum + next);
}


int solution(int n) {

	//1~n까지 반복하여 넘겨줌
	for (int i = 1; i <= n; i++) 
		Check(n, i, i);

	return answer;
}

int main() {
	int N = 15;

	cout << solution(N) << endl;

	return 0;
}