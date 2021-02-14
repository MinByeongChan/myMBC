#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++) {
		cout << "------" << t << "------" <<endl;
		//�ؾ�� K�� ����µ� M���� �ð��� �ҿ� 
		int N=0, M=0, K=0;
		int time[101] = {0,};
		//INPUT
		cin >> N >> M >> K;
		
		bool enable = true;
		//�ؾ ���� 
		int cnt = 0;
		//������ �����ִ� �ð� 
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
			
			//��ü ���� �ð��� �ǹ� 
			total_time += time[i];
			
			//�ð��� �ؾ ���� ���� 
			cnt += (total_time / M) * K;
			//�ѻ���� �ϳ��� �ؾ�� ��ٴ°��� ������ �ؾ ������ 1 ���� 
			cnt--;
			//time[i]�� ¦���� total_time�� ���󺹱� 
			if(time[i]/M == 0) total_time -= time[i];
			//time[i]�� Ȧ���� �ؾ ������ �ð���ŭ ���� 
			else total_time -= (time[i]-(time[i]%M));
			cout << "cnt: "<< cnt << endl;
			
			//�����ִ� �ؾ�� ������ false 
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
