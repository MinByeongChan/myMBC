#include <iostream>

using namespace std;

//�κ��� ������ ������ ����
//���� �״�� ���ϴ� ��� �迭�� �迭 ������ ���̰���
//nSum�迭�� �����ϰ� �Ȱ��� ������� ���� 
int main(int argc, char** argv) {
	int N, Q, nSum[10001];
	int A = 0, B = 0;
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++){
		//Ȧ¦ �����ư��� �Է� 
		if(i%2!=0) {
			scanf("%d", &A);
		}
		else {
			scanf("%d", &B);
		}
		 
		if((B-A) < 0) nSum[i+1] = nSum[i] + (-1)*(B-A);
		else nSum[i+1] = nSum[i] + (B-A);
		
	}
	
	for(int i=0; i<Q; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		//���� �����ϴ� ����� �ϴٺ��� �ε����� �ϳ��� �и�
		//����� ������� ��� ��  
		printf("%d\n", nSum[e] - nSum[s]);
	}

	return 0;
}
