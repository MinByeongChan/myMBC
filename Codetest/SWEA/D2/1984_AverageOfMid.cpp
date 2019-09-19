#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++){
		int arr[10] = {0,};
		double sum=0, m=0, l=10000;
		double result=0;
		
		//INPUT
		for(int i=0; i<10; i++){
			cin >> arr[i];
			if(arr[i] < 0 || arr[i] > 10000) return 0;
			m = max(m, arr[i]);
			l = min(l, arr[i]);
		}
		
		for(int i=0; i<10; i++){
			if(arr[i] == m) continue;
			if(arr[i] == l) continue;
			sum += arr[i];
		}
		result = round(sum / 8);
		cout << "#"<<t<< " "<< result << endl;
	}
	cin >> T;
	
	return 0;
}
