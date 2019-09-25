#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++) {
		cout << "------" << t << "------" <<endl;
		//붕어빵을 K개 만드는데 M초의 시간이 소요 
		int N=0, M=0, K=0;
		int time[101] = {0,};
		//INPUT
		cin >> N >> M >> K;
		
		bool enable = true;
		//붕어빵 갯수 
		int cnt = 0;
		//루프당 남아있는 시간 
		int total_time = 0;
		
		//time Initialization
		for(int i=0; i<N; i++) {
			cin >> time[i];
		}
		
		for(int i=0; i<N; i++) {
			if(time[0] < M){
				enable = false;
				break;
			}
			
			//전체 남는 시간을 의미 
			total_time += time[i];
			
			//시간당 붕어빵 생산 갯수 
			cnt += (total_time / M) * K;
			//한사람당 하나씩 붕어빵을 산다는것을 전제로 붕어빵 개수를 1 감소 
			cnt--;
			//time[i]가 짝수면 total_time을 원상복구 
			if(time[i]/M == 0) total_time -= time[i];
			//time[i]가 홀수면 붕어빵 생산한 시간만큼 감소 
			else total_time -= (time[i]-(time[i]%M));
			cout << "cnt: "<< cnt << endl;
			
			//남아있는 붕어빵이 없으면 false 
			if(cnt == 0) enable = false;
		}
		
		//OUTPUT 
		cout << "#" << t << " ";
		if(enable == true)
			cout << "Possible" << endl;
		
		else 
			cout << "Impossible" << endl;
		
	}
	
	cin >> T;
	
	return 0;
}
