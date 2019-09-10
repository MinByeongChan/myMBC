#include <iostream>
#include <algorithm>

#define MAX 51

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++){
		int N;
		cin >> N;
		int arr[MAX]= {0, };
		
		for(int i=0; i<N; i++){
			cin >> arr[i];
		}
		sort(arr, arr+N);
		cout << "#" << t << " ";
		for(int i=0; i<N; i++){
			cout << arr[i] <<" ";
		}
		cout << endl;
	}

	return 0;
}
