#include <iostream>

#define ARR_MAX 100000
#define M_MAX 1000000000

using namespace std;

//이분탐색할 때 오버플로우가 발생할 수 있다.
//항상 long long 자료형을 애용하자 
int main(int argc, char** argv) {
	int N, M;
	int height[ARR_MAX];
	cin >> N >> M;
	
	for(int i=0; i<N; i++) {
		cin >> height[i];
	}
	
	int lo = 0, hi = M_MAX;
	
	while(lo+1 < hi) {
		//최대 10000000부터 시작하여 매 시도에 반으로 나눔
		int mid = (lo+hi) / 2;
		//cout << mid << endl;
		
		//이분 탐색마다 sum을 0으로 초기화 
		long long sum = 0;
		for(int i=0; i<N; i++) {
			//나무 높이중에 mid보다 큰 값이 존재하면
			//mid와의 차를 sum에 누적 
			if(height[i] > mid) sum +=height[i] - mid;
		}
		if(sum >= M) lo = mid;
		//hi의 값을 반으로 줄이며 반복 
		else hi = mid;
	}
	
	cout << lo << endl;

	cin >> N;
	
	return 0;
}
