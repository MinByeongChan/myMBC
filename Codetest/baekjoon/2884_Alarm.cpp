#include <iostream>
using namespace std;

int main() {
	int H, M, fH=0, fM=0;
	cin >> H >> M;
	
	if (M - 45 < 0) {
		if (H - 1 < 0) {
			fH = 23;
		}
		else fH = H-1;
		
		fM = 60 - 45 + M;
		cout << fH << " " << fM;
	}
	else cout << H << " " << M - 45;
	
	cin >> H;

	return 0;
}