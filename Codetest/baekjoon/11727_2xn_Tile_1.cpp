#include <iostream>

using namespace std;

int data[100000];

//전형적인 DP문제 
//점화식만 알면 끝 
int tile(int x){
	if(x==1) return 1;
	if(x==2) return 2;
	//알고리즘 효율성 향상을 위한 메모이제이션 
	if(data[x] != 0) return data[x] % 10007;
	data[x] = tile(x-1) + tile(x-2);
	
	//스택 오버플로우를 방지하기 위해 나머지를 출력 
	return data[x] % 10007;
}

int main(int argc, char** argv) {	
	int n;
	cin >> n;
	if(n<1 || n>1000) return 0;
	
	cout << tile(n);

	return 0;
}


