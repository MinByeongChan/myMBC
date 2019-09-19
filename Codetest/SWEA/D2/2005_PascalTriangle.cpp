#include <iostream>

using namespace std;

//배열 두개를 사용하여 구현  
int arrA[11]={1};
int arrB[11]={1};

//파스칼의 삼각형 출력 함수
void Triangle(int x){
	
	//홀수면 arrA 
	if(x%2 != 0) {
		for(int i=0; i<x; i++){
			//첫항과 마지막 항은 무조건 1 
			if(i==0 || i==x-1) arrA[i] = 1;
			//나머지는 다른 배열의 앞뒤 항을 더함 
			else arrA[i] = arrB[i-1] + arrB[i];
		}
		for(int i=0; i<x; i++){
			cout << arrA[i] << " ";
		}
	}
	//짝수면 arrB, 홀수와 똑같음  
	else {
		for(int i=0; i<x; i++){
			if(i==0 || i==x-1) arrB[i] = 1;
			else arrB[i] = arrA[i-1] + arrA[i];
		}
		for(int i=0; i<x; i++){
			cout << arrB[i] << " ";
		}
	} 
	
	cout << endl;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		cin >> N;
		
		cout <<"#"<<t<<" "<< endl;
		
		//OUTPUT 
		for(int i=1; i<=N; i++) {
			Triangle(i);
		}		
	}
	
	cin >> T;
	
	return 0;
}
