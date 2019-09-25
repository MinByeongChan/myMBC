#include <iostream>
#define MAX 1000
#define min_MAX 100000

using namespace std;

int arr[MAX];
int direct[4] = {1, -1, 2, -2};

int Check(int x) {
	int min = min_MAX;
	
	for(int i=0; i<4; i++){
		if(arr[x] < arr[x+direct[i]]) {
			min = min_MAX;
			break;
		}
		
		if(min > arr[x] - arr[x+direct[i]]) {
			min = arr[x] - arr[x+direct[i]];
		}
		
		
	}
//	cout << "min : " << min << endl;
	if(min == min_MAX) return 0;
	else return min;
}

int main(int argc, char** argv) {
	
	for(int t=1; t<=10; t++) {
		int N;
		cin >> N;
		int result = 0;
		fill(arr, arr+MAX, 0);
		
		//INPUT 
		for(int i=0; i<N; i++){
			cin >> arr[i];
		}
		
		for(int i=2; i<N-2; i++) {
			int a = Check(i);
//			printf("%d \n", a);
			result+=a;
		}
		cout << "#"<<t<< " " << result << endl; 
	}
	
	cin >> arr[0];

	return 0;
}
