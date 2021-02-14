#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    //대기중인 트럭 
    queue<int> q1;
    //현재 다리를 건너고 있는 트럭 
    queue<int> q2;
    //다리를 건넌 트럭 
    queue<int> q3;
    
    //현재 다리를 건너고 있는 트럭들의 총 무게 
    int curr_weight = 0;
    //대기중인 트럭의 갯수 
    int TRUCK_SIZE = truck_weights.size();
	//트럭들의 거리
	//거리+1이 되면 다리를 건넜다고 판단 
    vector<int> distance(TRUCK_SIZE, -1);
    
    for(int i=0; i<TRUCK_SIZE; i++) {
    	q1.push(truck_weights[i]);
	}
	
	int d=0;
	int x;
    while(1) {
    	//모든 트럭이 다리를 건너면 break 
    	if(q3.size() == TRUCK_SIZE) break; 
    	time++;
    	
    	//q1이 비어있고 다리가 무게를 견뎌낼 수 있을 때 push 
		if(!q1.empty() && curr_weight + q1.front() <= weight) {
			x = q1.front();
			q1.pop();
			q2.push(x);
			curr_weight += x;
			//0으로 만들어줌 이후 time++될때마다 거리도 +1씩 증가 
			if(distance[d] != bridge_length) {
				distance[d++] = 0;
			}
		}
				
		for(int i=0; i<TRUCK_SIZE; i++) {
			//q2로 push가 된 트럭은 0이상의 값을 의미
			//거리가 +1씪 증가		 
			if(distance[i] != -1 && distance[i] <= bridge_length) {
				distance[i]++;
			}
			
			//다리를 건너면 q3에 push
			
			if(distance[i] == bridge_length + 1) {
				int y = q2.front();
				q2.pop();
				//현재 다리 무게를 감소 
				curr_weight -= y;
				//distance를 더이상 카운트 하지 않게 위해 -1초기화  
				distance[i] = -1;
				q3.push(y);
				
				//트럭이 건넌 상태에서 동시에 다른 트럭이 들어올 때를 위함
				//동작원리는 위와 같음 
				if(!q1.empty() && curr_weight + q1.front() <= weight) {
					x = q1.front();
					q1.pop();
					q2.push(x);
					curr_weight += x;
					if(distance[d] != bridge_length) {
						distance[d++] = 0;
					}
				}
			}
			
		}
		
	}
    
    return time;
}

int main(int argc, char** argv) {
	vector<int> truck_weights{10};
	int weight = 100;
	int bridge_length = 100;
	
	cout << solution(bridge_length, weight, truck_weights) << endl;
	
	cin >> weight;
	return 0;
}
