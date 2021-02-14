#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//결과 출력 큐 
queue<int> q;
//방문 배열 
bool v[101] = {false, };
int V_SIZE, cnt;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
	V_SIZE = progresses.size();
	day = 1;
	int end = V_SIZE;
	while(end != 0){
		//하루에 반환할 개수 
		cnt = 0;
		//매번 전체 배열을 스캔하고 speeds를 더해줌 
		for(int i=0; i<V_SIZE; i++) {
			if(v[i] == true) continue;
			if(progresses[i] != 100 && !v[i])
				progresses[i] += speeds[i];
			if(progresses[i] >= 100 && !v[i]){
				if(i == 0){
					v[i] = true;
					cnt++;
				}
				else if(i != 0 && v[i-1]){
					v[i] = true;
					cnt++;
				}
				
			}
			
			cout << "progresses[i]: " << progresses[i] << endl;;
		}
		
		cout << "cnt: " << cnt << endl;
		
		if(cnt > 0) {
			q.push(cnt);
			end -= cnt;
		}
		
		day++;
	}
	
	while(!q.empty()){
		int x = q.front();
		answer.push_back(x);
		q.pop();
		cout << "x: " << x << endl;
	}
	
    
    return answer;
}

int main(int argc, char** argv) {
	vector<int> progresses{93, 30, 55};
	vector<int> speeds{1, 30, 5};
	
	for(int i=0; i<progresses.size(); i++) {
		cout << progresses[i] << endl;
	}
	solution(progresses, speeds);
	
	cin >> progresses[0];
	
	return 0;
}
