#include <iostream>

using namespace std;

//�� �̷� ������ �ֳ� ������ �������� ���� ��������
//���� ��Ȳ�������� 
int main(int argc, char** argv) {
	int T;
	cin>> T;
	for(int t=1; t<=T; t++) {
		int N;
		cin >> N;
		
		printf("#%d ", t);
		for(int i=0; i<N; i++) {
			printf("1/%d ", N);
		}
		printf("\n");	
	}

	cin>> T;
	
	return 0;
}
