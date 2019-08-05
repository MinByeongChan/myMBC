#include <iostream>

using namespace std;


int dn(int x){
	int result=0;
	int temp = x;
	
	while(1){
		if(temp >= 1){
			result += (temp % 10);
			temp /= 10;
		}
		else break;
	}
	
	return result + x;
}


int main() {
	int n;
	int i=1;
	
	cin >> n; // 자연수 n을 입력 
	
	// 생성자 출력	
	if(n <= 1000000 && n >= 1){
		for(int i=1; i<=n; i++){
			// 입력한 정수가 dn결과(생성자)일때 출력
			if(n == dn(i)){
				cout << i << endl;
				return 0;
			}
		}
		//생성자가 존재하지 않을 시 0출력
		cout << 0 << endl;
	}
}
