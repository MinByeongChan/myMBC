#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int n; //동전의 종류
	int sum = 0; // 가치의 합 
	int result = 0;// 동전개수의 최소값 
	int temp = 0; //목 임시 저장변수
	
	cin >> n >> sum;
	int *a = new int[n];
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	

	for(int i=n-1; i>=0; i--){		 
		//각 단위화폐마다 몫을 구해 더해준다
		if((sum/a[i]) >= 1){
			temp = sum / a[i];
			result += temp;
			sum %= a[i];
		}
		temp = 0;
	}
	
	//출력
	cout << result ;
	//동적메모리 비활성화
	delete[] a;

	return 0;
}
