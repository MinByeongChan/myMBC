#include <iostream>

using namespace std;

int result[10] = {-1, };

void SheepCount(int x) {
	int temp = x;
//	cout << "SheepCount()" << endl;
	while(temp != 0) {
		int a = temp%10;
		if(result[a] == -1) {
			result[a] = 1;
//			printf("%d ", a);
		}
		temp/=10;
	}
//	cout << endl;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N;
		result[10] = {-1, };
		cin >>N;
		
		//ī��Ʈ���� N�ǰ��� ���ذ� temp���� 
		int N_temp = N;
		
		//�迭�� -1�� �ʱ�ȭ 
		fill(result, result+10, -1);
		
		while(1) {
//			cout << "N : " << N << endl;
			//�ڸ��� ������ ���� �迭�� ����
			//����Ǵ� ���� 1�� ����
			//-1�̸� ���� ����x, 1�̸� ���� 
			SheepCount(N);
			
			//�ݺ��� Ż�� ���� 
			int exit = 0;
			for(int i=0; i<10; i++) 
				if(result[i] != -1) exit++;
			
			if(exit == 10) break; // ��� ������ �� ������ �� exit 
			//���� ������ ���� �ִٸ�
			//N�� N�� ���ذ���. 
			else N += N_temp;
		}
		
		//xN�� ���� N�� ��� 
		cout << "#"<<t<< " "<< N << endl;
		
	}

	cin >> T;
	return 0;
}
