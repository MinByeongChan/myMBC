#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++) {
		int N;
		int result=0;
		cin >> N;
		
		//Â¦¼öÀÏ¶© -, È¦¼öÀÏ¶© + 
		for(int i=1; i<=N; i++) {
			if(i%2 == 0) result -= i;
			else result += i; 
			cout << result << endl;
		}
		
		//OUTPUT
		cout <<"#"<<t<< " "<<result<<endl;
	}
	
	cin >> T;

	return 0;
}
