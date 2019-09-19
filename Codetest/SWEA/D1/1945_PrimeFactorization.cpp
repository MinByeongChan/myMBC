#include <iostream>

using namespace std;


int* Resolve(int prime[], int x){
	int temp=x;
	while(temp != 1){
		if(temp % 2 == 0) {
			temp /= 2;
			prime[0]++;
			continue;	
		}
		if(temp % 3 == 0) {
			temp/=3;
			prime[1]++;
			continue;	
		}
		if(temp % 5 == 0) {
			temp/=5;
			prime[2]++;
			continue;	
		}
		if(temp % 7 == 0) {
			temp/=7;
			prime[3]++;
			continue;	
		}
		if(temp % 11 == 0) {
			temp/=11;
			prime[4]++;
			continue;	
		}
	}
	
	return prime;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		int N;
		int arr[5] = {0,};
		int *p;
		cin >> N;
		
		p = Resolve(arr, N);
		
		//Ãâ·Â 
		printf("#%d ",t);
		for(int i=0; i<5; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	cin >> T;
	return 0;
}
