#include <iostream>
#include <vector>

using namespace std;

int N, P;
int cnt;

class Vec {
public :
	int N;
	vector<vector<int>> arr;
	vector<bool> visited;

	Vec() : N(0) {}
	Vec(int n) : N(n+1) {
		arr.resize(n+1);
		visited.resize(n+1);
	}
	void Edge(int u, int v) {
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	void dfs() {
		fill(visited.begin(), visited.end(), false);
		dfs(1);
	}

private:
	void dfs(int start) {
		if (visited[start]) return;
		visited[start] = true;

		cnt++;

		for (int i = 0; i < arr[start].size(); i++) {
			int y = arr[start][i];
			dfs(y);
		}
	}

};

int main() {
	cin >> N;
	cin >> P;

	Vec v(N);
	//바이러스 걸린 컴퓨터 개수 카운트 변수
	cnt = 0;
	
	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		v.Edge(a, b);
	}
	
	v.dfs();
	cout << cnt - 1 << "\n";

	cin >> N;

	return 0;
}