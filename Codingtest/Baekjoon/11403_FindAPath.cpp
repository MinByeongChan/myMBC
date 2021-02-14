#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// 그래프 클래스로 구현
class Gragh {
public:
	int n;
	vector<vector<int> > arr;
	vector<bool> visited;
	Gragh(int n1) : n(n1) {
		arr.resize(n1+1);
		visited.resize(n + 1, false);
	};

	void addEdge(int u, int v) {
		arr[u].push_back(v);
	}

	bool bfs(int start, int end) {
		fill(visited.begin(), visited.end(), false);
		queue<int> q;

		// queue비우기
		// 2중 반복문에서 bfs가 한번 시행되면 queue가 남아있는 경우가 있으므로 
		while (!q.empty())
			q.pop();
		
		// bfs진행
		q.push(start);
		visited[start] = true;

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			
			//cout << x << " ";

			for (int i = 0; i < arr[x].size(); i++) {
				int y = arr[x][i];
				// end가 발견되는 즉시 true 반환
				if (y == end) return true;
				
				if (!visited[y]) {
					q.push(y);
					visited[y] = true;
				}
			}
		}
		// end를 못찾고 queue를 모두 비워지게 되면 false 반환
		return false;
	}
};


int main() {
	int N; // 이중 배열 크기
	cin >> N;

	Gragh G(N);

	// result는 출력할 배열
	vector<vector<bool> > result;
	result.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
		result[i].resize(N + 1, false);

	//INPUT
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			int input1;
			cin >> input1;
			//input1이 1이면 단방향 그래프를 구성
			if (input1 == 1) {
				result[j][i] = true;

				//cout << "(" << j << ", " << i << ")\n";
				G.addEdge(j, i);
			}
		}
	}

	// bfs결과를 result배열에 담음
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			result[j][i] = G.bfs(j, i);
			//cout << "\n";
		}
	}
	
	//cout << "--- result --- \n";
	
	//OUTPUT
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cout << result[j][i] << " ";
		}
		cout << "\n";
	}

	return 0;
}