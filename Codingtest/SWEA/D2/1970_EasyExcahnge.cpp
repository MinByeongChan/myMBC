#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		int money[8] = {0, };
		cin >> N;
		
		while(N != 0) {
			if(N >= 50000) {
				money[0]++;
				N-=50000;
				continue;
			}
			if(N >= 10000) {
				money[1]++;
				N-=10000;
				continue;
			}
			if(N >= 5000) {
				money[2]++;
				N-=5000;
				continue;
			}
			if(N >= 1000) {
				money[3]++;
				N-=1000;
				continue;
			}
			if(N >= 500) {
				money[4]++;
				N-=500;
				continue;
			}
			if(N >= 100) {
				money[5]++;
				N-=100;
				continue;
			}
			if(N >= 50) {
				money[6]++;
				N-=50;
				continue;
			}
			if(N >= 10) {
				money[7]++;
				N-=10;
				continue;
			}
			
		}
		
		//OUTPUT
		cout << "#" << t << endl;
		for(int i=0; i<8; i++) {
			cout << money[i] << " ";
		}
		cout << endl;
	}
	
	cin >> T;

	return 0;
}
