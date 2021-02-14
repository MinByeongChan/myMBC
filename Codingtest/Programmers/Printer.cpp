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
    
    //오름차순으로 자동으로 누적됨
	//stack이랑 오히려 비슷함
	//top 방향으로 오름차순 정렬
	//priorites의 모든 인덱스를 push 
    for(int i=0; i<pri_SIZE; i++){
	   	pq.push(priorities[i]);
	}
	
	//priorites의 첫 인덱스부터 끝까지 스캔하며
	//top(우선순위가 높은 항)과 일치할때까지 비교 
	int p=0;
	//pq가 비어있을때까지 진행 
    while(!pq.empty()) {
//    	cout << "p: "<< p << endl;
    	
    	
		for(int i=p; i<pri_SIZE; i++) {
	    	if(pq.top() == priorities[i]) {
//	    		cout<< "top: " << pq.top() << endl;
	    		pq.pop();
	    		cnt++;
	    		if(i == location) return cnt;
	    		//p를 i+1로 초기화 하여 뒤에 인덱스를 스캔 
	    		p=i+1;
			}
			//index의 끝까지 도달하면 다시 i=0으로 초기화 
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
