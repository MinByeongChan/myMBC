#include <iostream>

using namespace std;

//뭐 이런 문제가 있나 생각이 들정도로 쉬운 문제ㅎㅎ
//많이 당황스럽구만 
int main(int argc, char** argv) {
	int T;
	cin>> T;
	for(int t=1; t<=T; t++) {
		int N;
		cin >> N;
		
		printf("#%d ", t);
		for(int i=0; i<N; i++) {
			printf("1/%d ", N);
		}
		printf("\n");	
	}

	cin>> T;
	
	return 0;
}
