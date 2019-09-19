#include <iostream>
#define MAX 1001
using namespace std;

int main(int argc, char** argv) {
	int T ;
	int p;
	int arr[MAX];
	
	cin >> T;
	
	for(int i=1; i<=T; i++){
		cin >> p;
		int distance = 100001;
		int result_p = 0;
		
		//던진 돌의 위치 입력 
		for(int j=0; j<p; j++)
			cin >> arr[j];
		
		for(int j=0; j<p; j++){
			//절대값 처리를 위해 음수이면 양수로 변환 
			if(arr[j] < 0) arr[j] *= (-1);
			//0까지의 거리 차이 최소값을 구한다. 
			if(arr[j] >= 0){
				if(arr[j]-0 <= distance) {
					distance = arr[j];
				}
			}
		}
		
		//동일한 최소값의 중복을 체크 
		for(int j=0; j<p; j++){
			if(arr[j] <= distance) result_p++;
		}
		
		printf("#%d %d %d\n", i, distance, result_p);
	}
	
	
	cin >> T;
	

	return 0;
}
