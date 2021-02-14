#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

int main() {
	vector<int> answer;
	int n = 3;
	int m = 12;
	
	int a = n, b = m, p = 0; // 배열에 대한 포인터 
	int a1[MAX] = {0, }; // 나누어지는 인수를 각 배열에 저장 
	int divisor = 2; // 나누는 수 
	
	while(1) {
		//divisor가 n또는 m일 떄 반복문 탈출 
		if(divisor > n || divisor > m) {
			break;	
		}
		cout << divisor << endl;
		//소인수 분해하는 단계
		//각 인수들을 배열a1에 저장 
		if((a % divisor) == 0 && (b % divisor) == 0) {
			a1[p] = divisor;
			printf("(%d / %d) %d\n", a, b, a1[p] );
			a /= divisor;
			b /= divisor;
			p++;
		}
		//나누어지지 않으면 divisor을 하나씩 증가시킴 
		else divisor++;
		
	}
	//result1,2 각각 최대공약수, 최소공배수를 의미 
	int result1 = 1;
	int result2 = 1;
	if(p>=1){
		for(int i=0; i<=p; i++){
			if(a1[i] != 0)  result1 *= a1[i];
		}
	}
	//최대공약수에서 n,m에 대한 서로수를 각각 곱함 
	result2 = result1*a*b;
	
	cout << result1 << " " << result2 ;
	
    return 0;
}


