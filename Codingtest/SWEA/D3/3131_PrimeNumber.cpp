#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000

using namespace std;


int main(int argc, char** argv) {
//	long long int arr[MAX] = {0,};
	vector<long long int> arr;
	
	for(int i=2; i<MAX; i++) {
//		arr[i] = i;
		arr.push_back(i);
	}
	
	
	for(int i=2; i<sqrt(MAX); i++) {
		if(arr[i] == 0) continue;
		for(int j=i+i; j<MAX; j+=i) {
			arr[j] = 0;
		}
	}	
	
	for(int i=2; i<MAX; i++) {
		if(arr[i] != 0) {
			cout << arr[i] <<" ";
		}
	}

	cin >> arr[0];
	
	return 0;
}
