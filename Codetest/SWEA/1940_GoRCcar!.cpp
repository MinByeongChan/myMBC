#include <iostream>

using namespace std;


int main(int argc, char** argv) {
	int T; // �׽�Ʈ ���̽� 
	cin >> T;
	
	for(int t=1; t<=T; t++){
		int N;
		int distance=0; // ���� �Ÿ� 
		int v=0; // �ӵ� 
		
		cin >> N; // ��� �� 
		
		for(int i=0; i<N; i++){
			int a, b;
			cin >> a;
			if(a==0) {
				distance += v;
				continue;
			}
			cin >> b;
			
			// 1�̸� ���� 
			if(a==1) v+=b;
			// 0�̸� ���� 
			if(a==2) v-=b;
			//���� �ӵ��� ������ 0���� �ʱ�ȭ 
			if(v <= 0) v=0; 
			//1��ɴ� ����� ����Ÿ��� ���� 
			distance += v;
		}
		
		//1���̽��� 1��� ��� 
		printf("#%d %d\n", t, distance);
		
	}

	return 0;
}
