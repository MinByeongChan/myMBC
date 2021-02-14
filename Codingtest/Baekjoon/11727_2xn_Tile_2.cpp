#include <iostream>
#define MAX 1000001

using namespace std;

int data[MAX];

//dp의 전형적인 문제
//점화식을 알면 구할 수 있다.
//n에 따른 타일이 어떻게 변화하는지 파악하고 점화식을 구할줄 알면 끝나는 문제 
int tile(int x){
	if(x==1) return 1;
	if(x==2) return 3;
	if(data[x] != 0) return data[x] % 10007;
	data[x] = 2 * tile(x-2) + tile(x-1);
	return data[x] % 10007;
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	if(n<1 || n>1000) return 0;
	
	//출력 
	cout << tile(n);
	
	return 0;
}
