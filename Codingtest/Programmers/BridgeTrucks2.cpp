#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    //������� Ʈ�� 
    queue<int> q1;
    //���� �ٸ��� �ǳʰ� �ִ� Ʈ�� 
    queue<int> q2;
    //�ٸ��� �ǳ� Ʈ�� 
    queue<int> q3;
    
    //���� �ٸ��� �ǳʰ� �ִ� Ʈ������ �� ���� 
    int curr_weight = 0;
    //������� Ʈ���� ���� 
    int TRUCK_SIZE = truck_weights.size();
	//Ʈ������ �Ÿ�
	//�Ÿ�+1�� �Ǹ� �ٸ��� �ǳԴٰ� �Ǵ� 
    vector<int> distance(TRUCK_SIZE, -1);
    
    for(int i=0; i<TRUCK_SIZE; i++) {
    	q1.push(truck_weights[i]);
	}
	
	int d=0;
	int x;
    while(1) {
    	//��� Ʈ���� �ٸ��� �ǳʸ� break 
    	if(q3.size() == TRUCK_SIZE) break; 
    	time++;
    	
    	//q1�� ����ְ� �ٸ��� ���Ը� �ߵ��� �� ���� �� push 
		if(!q1.empty() && curr_weight + q1.front() <= weight) {
			x = q1.front();
			q1.pop();
			q2.push(x);
			curr_weight += x;
			//0���� ������� ���� time++�ɶ����� �Ÿ��� +1�� ���� 
			if(distance[d] != bridge_length) {
				distance[d++] = 0;
			}
		}
				
		for(int i=0; i<TRUCK_SIZE; i++) {
			//q2�� push�� �� Ʈ���� 0�̻��� ���� �ǹ�
			//�Ÿ��� +1�� ����		 
			if(distance[i] != -1 && distance[i] <= bridge_length) {
				distance[i]++;
			}
			
			//�ٸ��� �ǳʸ� q3�� push
			
			if(distance[i] == bridge_length + 1) {
				int y = q2.front();
				q2.pop();
				//���� �ٸ� ���Ը� ���� 
				curr_weight -= y;
				//distance�� ���̻� ī��Ʈ ���� �ʰ� ���� -1�ʱ�ȭ  
				distance[i] = -1;
				q3.push(y);
				
				//Ʈ���� �ǳ� ���¿��� ���ÿ� �ٸ� Ʈ���� ���� ���� ����
				//���ۿ����� ���� ���� 
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
