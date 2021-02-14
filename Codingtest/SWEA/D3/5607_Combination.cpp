#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N, R;
		int result = 0;
		cin >> N >> R;
		int n=N, r=R;
		int u=1, v=1;
		
		for(int i=0; i<R; i++) {
			u *= n;
			v *= r;
			n--;
			r--;
		}
		result = u / v;
		result %= 1234567891;
		
		cout << "#"<< t<< " " << result << endl;
	}

	cin >> T;
	
	return 0;
}
