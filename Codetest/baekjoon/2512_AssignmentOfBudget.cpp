#include <iostream>
#include <vector>

#define M_MAX 1000000000

using namespace std;

//이분탐색으로 구현 
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
	
	// 예산 범위안에서 모두 처리할 수 있으면 바로 최대값을 출력 
	if(sum <= M) {
		int tmp_max = 0;
		for(int i=0; i<N; i++) {
			if(tmp_max < budget[i]) 
				tmp_max = budget[i];
		}
		cout << tmp_max << endl;
	} 
	
	else {
		//시작을 0, 끝을 M으로 설정 
		int lo = 0, hi = M;
		while(lo+1 < hi) {
			int mid = (lo+hi) / 2;
	//		cout << "mid: " << mid << endl;
	//		cout << "low: " << lo << endl;
			
			sum = 0;
			// budget에 대한 sum을 구함 
			for(int i=0; i<N; i++) {
				//한 부서에 대해 할당할 예산이 더 크면 부서의 최대 요구 예산을 더함  
				if(budget[i] < mid) sum += budget[i];
				else sum += mid;
			}
			
	//		cout << "sum: "<< sum << endl;
			
			// 이조건이 매우 중요!! 
			if(sum < M) lo = mid;
			else hi = mid;
		}
		
		cout << lo;	
	}
	
	cin >> N;
	
	return 0;
}
