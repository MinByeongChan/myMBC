#include <iostream>

using namespace std;

//�κ���
//�κй迭�� ���� ���ϴ� ����
//11659 �ձ��ϱ�4������ ������
//�ſ� ����
//�� �˰����� �� �˾Ƶ��� �����ҵ� �� 
int main(int argc, char** argv) {
	int N, M, nSum[100001] = {0, };
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		nSum[i+1] = nSum[i] + A;
	}
	
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", nSum[e]-nSum[s-1]);
	}

	return 0;
}
