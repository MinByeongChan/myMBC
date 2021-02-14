#include <iostream>

using namespace std;


int N, M;
int arr[16][16] = {0,};

// ����ã���� �ð� �� �ɷȴ� ���� ��... 
int Sum(int x, int y) {
	int sum = 0;
	//���ϴ� ������ N���� Ŀ�� ��� 0��ȯ  
	if(x+M > N || y+M > N) return 0;
	for(int i=y; i<y+M; i++){
		for(int j=x; j<x+M; j++) {
			//�ĸ�ä ũ�⸸ŭ ���� ����  
			sum += arr[j][i];
		}
	}
	
	return sum;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int result=0;
		int max = 0;
		// N : �迭 ����, M : �ĸ�ä ũ��
		cin >> N >> M;
		
		//NxN�迭 �ʱ�ȭ 
		for(int i=0; i<16; i++) {
			fill(arr[i], arr[i]+16, 0);
		}
		
		//NxN�迭 ���� �Է� 
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				cin >> arr[j][i];
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				result = Sum(j, i);
				//�ִ밪 ���ϱ�  
				if(result > max ) max = result;
			}
		}
		//OUTPUT 
		cout << "#" << t << " "<< max <<endl;
		 
	}
	
	
	return 0;
}
