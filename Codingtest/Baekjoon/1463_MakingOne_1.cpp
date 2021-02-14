#include <iostream>

using namespace std;

int solve(int n){
	if(n==1) return 1;
	int temp = n; // 10의 배수 검사	
	int result=0; // 연산 횟수 
	
	while(1) {
		//10의 배수 검사 
		while(1){
			if((temp % 10) != 0) break;
			temp /= 10;
			if(temp == 1){
				n-=1;
				cout << n << endl;
				result++;
				break;
			}
		}
		
		if(n%3 != 0 && n%2 != 0) {
			n-=1;
			cout << n << endl;
			result++;
		}
		
		
		if(n%3 == 0){
			n = n/3;
			cout << n << endl;
			result++;
		}
		
		else if(n%3 != 0){
			if(n%2 == 0){
				n = n/2;
				cout << n << endl;
				result++;
			}
		}
		
		if(n == 1) break;
	} 
		
	return result;
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	if(n >= 1 && n <=1000000)
		cout << solve(n) << endl;

	cin >> n;
	return 0;
}
