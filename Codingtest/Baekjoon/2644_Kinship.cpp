#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Gragh {
public:
	int n;
	int kinship = 1;
	vector<vector<int>> arr;

	Gragh() : n(0) {};
	Gragh(int n1) : n(n1+1) { arr.resize(n+1); };

	void addEdge(int u, int v) {
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	void bfs(int start, int end) {
		vector<bool> visited(n + 1, false);
		queue<int> q;
		q.push(start);
		visited[start] = true;
		
		while (!q.empty()) {
			int qSize = q.size();
			
			for (int i = 0; i < qSize; i++) {
				int x = q.front();
				q.pop();
				//cout << x << " ";
				for (int i = 0; i < arr[x].size(); i++) {
					int y = arr[x][i];
					
					if (y == end) return ;

					if (!visited[y]) {
						q.push(y);
						visited[y] = true;
					}
				}
			}

			kinship++;
		}

		kinship = -1;
	}
};



int main() {
	int n; // 전체 사람의 수
	cin >> n;

	int x, y; // 촌수를 계산해야하는 두 사람
	cin >> x >> y;

	int m; // 부모 자식들 간의 관계의 개수
	cin >> m;


	Gragh G(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G.addEdge(a, b);
	}

	G.bfs(x, y);


	cout << G.kinship;

	return 0;
}