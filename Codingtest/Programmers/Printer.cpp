#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int pri_SIZE = priorities.size();
    
    priority_queue<int> pq;
    int max = 0;
    int cnt=0;
    int result = priorities[location];
    
    //������������ �ڵ����� ������
	//stack�̶� ������ �����
	//top �������� �������� ����
	//priorites�� ��� �ε����� push 
    for(int i=0; i<pri_SIZE; i++){
	   	pq.push(priorities[i]);
	}
	
	//priorites�� ù �ε������� ������ ��ĵ�ϸ�
	//top(�켱������ ���� ��)�� ��ġ�Ҷ����� �� 
	int p=0;
	//pq�� ������������� ���� 
    while(!pq.empty()) {
//    	cout << "p: "<< p << endl;
    	
    	
		for(int i=p; i<pri_SIZE; i++) {
	    	if(pq.top() == priorities[i]) {
//	    		cout<< "top: " << pq.top() << endl;
	    		pq.pop();
	    		cnt++;
	    		if(i == location) return cnt;
	    		//p�� i+1�� �ʱ�ȭ �Ͽ� �ڿ� �ε����� ��ĵ 
	    		p=i+1;
			}
			//index�� ������ �����ϸ� �ٽ� i=0���� �ʱ�ȭ 
			if(i == pri_SIZE-1) {
				p=0;
			}
		}
		
	}
}

int main(int argc, char** argv) {
	vector<int> priorities{1, 1, 9, 1, 1, 1};
	int location = 0;
	
	cout << solution(priorities, location) << endl;
	
	cin >> location;
	return 0;
}
