#include <iostream>

#define MAX 100000

using namespace std;

int N;
int arr[MAX] = {0,};

int Addition(int x) {
	int start = x;
	int end = start;
	int max=0;
	
	for(int i=start; i<N-1; i++) {
		int result = 0;
		end++;
		
		for(int j=start; j<=end; j++) {
			result += arr[j];
		}
		cout << "start: " << x << " result: " << result << endl;
		if(result > max) max = result;
	}
	cout << "start: " << x << " max: " << max << endl;
	
	return max;
}


int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		int tmax = 0;
		//항의 개수 INPUT 
		cin >> N;
		
		fill(arr, arr+MAX, 0);
		
		
		//arr INPUT
		for(int i=0; i<N; i++) 
			cin >> arr[i];	
		
		
		for(int i=0; i<N-1; i++){
			int temp = Addition(i);
			if(tmax < temp) tmax = temp;
		}
		
		printf("#%d %d", t, tmax);
	}
	
	cin >> T;
	

	return 0;
}


