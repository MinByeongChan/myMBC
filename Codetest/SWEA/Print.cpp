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
		
		//���� ���� ��ġ �Է� 
		for(int j=0; j<p; j++)
			cin >> arr[j];
		
		for(int j=0; j<p; j++){
			//���밪 ó���� ���� �����̸� ����� ��ȯ 
			if(arr[j] < 0) arr[j] *= (-1);
			//0������ �Ÿ� ���� �ּҰ��� ���Ѵ�. 
			if(arr[j] >= 0){
				if(arr[j]-0 <= distance) {
					distance = arr[j];
				}
			}
		}
		
		//������ �ּҰ��� �ߺ��� üũ 
		for(int j=0; j<p; j++){
			if(arr[j] <= distance) result_p++;
		}
		
		printf("#%d %d %d\n", i, distance, result_p);
	}
	
	
	cin >> T;
	

	return 0;
}
