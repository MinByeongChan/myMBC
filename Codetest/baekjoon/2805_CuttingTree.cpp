#include <iostream>

#define ARR_MAX 100000
#define M_MAX 1000000000

using namespace std;

//�̺�Ž���� �� �����÷ο찡 �߻��� �� �ִ�.
//�׻� long long �ڷ����� �ֿ����� 
int main(int argc, char** argv) {
	int N, M;
	int height[ARR_MAX];
	cin >> N >> M;
	
	for(int i=0; i<N; i++) {
		cin >> height[i];
	}
	
	int lo = 0, hi = M_MAX;
	
	while(lo+1 < hi) {
		//�ִ� 10000000���� �����Ͽ� �� �õ��� ������ ����
		int mid = (lo+hi) / 2;
		//cout << mid << endl;
		
		//�̺� Ž������ sum�� 0���� �ʱ�ȭ 
		long long sum = 0;
		for(int i=0; i<N; i++) {
			//���� �����߿� mid���� ū ���� �����ϸ�
			//mid���� ���� sum�� ���� 
			if(height[i] > mid) sum +=height[i] - mid;
		}
		if(sum >= M) lo = mid;
		//hi�� ���� ������ ���̸� �ݺ� 
		else hi = mid;
	}
	
	cout << lo << endl;

	cin >> N;
	
	return 0;
}
