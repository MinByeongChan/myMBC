#include <iostream>

using namespace std;

int T; // 테스트 케이스
int R; // 반복 횟수 
char S[21] = {NULL, }; // 반복될 문자열 

//string으로 풀면 안됫었던 문제 ...
 
int main(int argc, char** argv) {
	cin >> T;
	if(T < 1 || T > 1000) return 0;
	for(int t=0; t<T; t++) {		
		scanf("%d %s", &R, &S);
		
		if(S == " ") continue;
		
		for(int i=0; S[i] != NULL; i++) {
			for(int j=0; j<R; j++) {
				cout << S[i];
			}
		}
		
		cout << endl;
	}
	
	cin >> T;

	return 0;
}
