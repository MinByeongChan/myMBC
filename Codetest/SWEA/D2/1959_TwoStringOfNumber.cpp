#include <iostream>

#define MAX 31
using namespace std;



int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N, M;
		long long int max=0;
		long long int arrA[MAX] = {0, };
		long long int arrB[MAX] = {0, };
		
		cin >> N >> M;
		
		//A배열 입력 
		for(int i=0; i<N; i++) cin >> arrA[i];
		//B배열 입력 
		for(int i=0; i<M; i++) cin >> arrB[i];
		if(N > M) {
			swap(N,M);
			for(int i=0; i<N; i++){
				swap(arrA[i], arrB[i]);
			}
		}
		
		int p=N-1;
		int q=0;
		long long int result=0;
		if(N < M){
			while(p != M){
				result = 0;
	//			printf("----- %d ~ %d -----\n", p, q);
				for(int i=p; i>=q; i--){
					result += (arrA[i]*arrB[i]);
					swap(arrA[i], arrA[i+1]);
	//				printf("p:%d / result : %d\n", i, result);
				}
	//			printf("result : %d\n", result);
				q++; p++;
				if(result > max) max = result;
			}
		}
		
		else if(N==M){
			result=0;
			for(int i=0; i<N; i++){
				result += (arrA[i]*arrB[i]);
			}
			max = result;
		}
		cout << "#" << t << " "<< max << endl; 
	}
	
	cin >> T;
	
	return 0;
}
