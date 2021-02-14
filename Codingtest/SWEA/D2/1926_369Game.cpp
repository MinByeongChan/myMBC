#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int temp = i;
		int b=0;
		while(temp != 0) {
			int a = temp % 10;
			if(a==0) {
				temp /= 10;
				continue;
			}
			if(a%3 == 0 || a%6 == 0 || a%9 == 0) {
				cout << "-";
				temp /= 10;
				b=1;
				continue;
			}
			else temp /= 10;
		}
		if(b==1) cout << " ";
		if(b==0) cout << i <<" ";
	}
	
	cin >> N;

	return 0;
}
