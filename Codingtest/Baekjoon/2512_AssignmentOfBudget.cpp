#include <iostream>
#include <vector>

#define M_MAX 1000000000

using namespace std;

//�̺�Ž������ ���� 
int main(int argc, char** argv) {
	int N, M;
	vector<int> budget;
 
	long long int sum = 0;
	
	//INPUT	
	cin >> N;
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		budget.push_back(tmp);
		sum += tmp;
	}
	cin >> M;
	
	// ���� �����ȿ��� ��� ó���� �� ������ �ٷ� �ִ밪�� ��� 
	if(sum <= M) {
		int tmp_max = 0;
		for(int i=0; i<N; i++) {
			if(tmp_max < budget[i]) 
				tmp_max = budget[i];
		}
		cout << tmp_max << endl;
	} 
	
	else {
		//������ 0, ���� M���� ���� 
		int lo = 0, hi = M;
		while(lo+1 < hi) {
			int mid = (lo+hi) / 2;
	//		cout << "mid: " << mid << endl;
	//		cout << "low: " << lo << endl;
			
			sum = 0;
			// budget�� ���� sum�� ���� 
			for(int i=0; i<N; i++) {
				//�� �μ��� ���� �Ҵ��� ������ �� ũ�� �μ��� �ִ� �䱸 ������ ����  
				if(budget[i] < mid) sum += budget[i];
				else sum += mid;
			}
			
	//		cout << "sum: "<< sum << endl;
			
			// �������� �ſ� �߿�!! 
			if(sum < M) lo = mid;
			else hi = mid;
		}
		
		cout << lo;	
	}
	
	cin >> N;
	
	return 0;
}
