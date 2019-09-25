#include <iostream>

using namespace std;


int main(int argc, char** argv) {
	
	for(int t=1; t<=10; t++){
		int T;
		cin >> T;
		
		int N, Expo;
		int result = 1;
	
		cin >> N >> Expo;
		
		while(Expo != 0) {
			result *= N;
			Expo--;
		}
		cout << "#" << T<< " " << result << endl; 
	
	}


	return 0;
}
