#include <iostream>

using namespace std;

int N, S;
int arr[20] = {0, };

int add = 0, cnt = 0;

int main(int argc, char** argv) {
	cin >> N >> S;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	int k=N;
	int p=0;
	for(int q=1; q<N-1; q++){
		p = q;
		printf("--- %d ---\n", q);
		for(int i=0; i<N-q; i++, p++){
			for(int j=i; j<=p; j++){
				add += arr[j];
			}
			printf("%d ", add);
			if(add == S){
				cnt++;
			}
			add = 0;
		}
		printf("\n");
	}
	
	cout << cnt << endl;
	
	return 0;
}
