#include <iostream>

using namespace std;

//�迭 �ΰ��� ����Ͽ� ����  
int arrA[11]={1};
int arrB[11]={1};

//�Ľ�Į�� �ﰢ�� ��� �Լ�
void Triangle(int x){
	
	//Ȧ���� arrA 
	if(x%2 != 0) {
		for(int i=0; i<x; i++){
			//ù�װ� ������ ���� ������ 1 
			if(i==0 || i==x-1) arrA[i] = 1;
			//�������� �ٸ� �迭�� �յ� ���� ���� 
			else arrA[i] = arrB[i-1] + arrB[i];
		}
		for(int i=0; i<x; i++){
			cout << arrA[i] << " ";
		}
	}
	//¦���� arrB, Ȧ���� �Ȱ���  
	else {
		for(int i=0; i<x; i++){
			if(i==0 || i==x-1) arrB[i] = 1;
			else arrB[i] = arrA[i-1] + arrA[i];
		}
		for(int i=0; i<x; i++){
			cout << arrB[i] << " ";
		}
	} 
	
	cout << endl;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		cin >> N;
		
		cout <<"#"<<t<<" "<< endl;
		
		//OUTPUT 
		for(int i=1; i<=N; i++) {
			Triangle(i);
		}		
	}
	
	cin >> T;
	
	return 0;
}
