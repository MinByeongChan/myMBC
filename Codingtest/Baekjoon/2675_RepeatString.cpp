#include <iostream>

using namespace std;

int T; // �׽�Ʈ ���̽�
int R; // �ݺ� Ƚ�� 
char S[21] = {NULL, }; // �ݺ��� ���ڿ� 

//string���� Ǯ�� �ȵ̾��� ���� ...
 
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
