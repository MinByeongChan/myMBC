#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

vector<bool> visited;

class Gragh {
public:
	int n;
	int v;
	vector<vector<int>> a;

	Gragh() : n(0) {};
	Gragh(int n1, int v1) : n(n1), v(v1) { a.resize(n1+1);  }
	
	void addEdge(int p, int q) {
		a[p].push_back(q);
		a[q].push_back(p);
	}

	void bfs() {
		queue<int> q;
		q.push(v);
		visited[v] = true;

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			cout << x << " ";
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				if (!visited[y]) {
					q.push(y);
					visited[y] = true;
				}
			}
		}
	}
	
	void sortList() {
		for (int i = 0; i < n; i++) {
			sort(a[i].begin(), a[i].end());
		}
	}

	void dfs(int x) {
		if (visited[x] == true) return;
		visited[x] = true;
		
		cout << x << " ";
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!visited[y]) {
				dfs(y);
			}
		}
		
	}

	
};

int main() {
	int N, M, V; // 정점의 개수, 간선의 개수, 시작할 노드번호
	cin >> N >> M >> V;

	Gragh G(N, V);

	for (int i = 0; i < M; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		
		G.addEdge(input1, input2);
	}
	G.sortList();

	visited.resize(N + 1, false);
	G.dfs(V);

	cout << "\n";

	fill(visited.begin(), visited.end(), false);
	G.bfs();

	
	return 0;
}