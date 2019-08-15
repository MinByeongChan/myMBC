#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int> > a(10000);
vector<bool> vb(N+1);
vector<bool> vd(N+1);

void addEdge(int u, int v){
	a[u].push_back(v);
	a[v].push_back(u);
}

void dfs(int d){
	if(vd[d]) return;
	vd[d] = true;
	printf("%d ", d);
	sort(a[d].begin(), a[d].end());
	for(int i=0; i<a[d].size(); i++){
		int y = a[d][i];
		cout << y << endl;
		dfs(y);
	}
}
void bfs(int b){
	queue<int> q;
	q.push(b);
	vb[b] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i];
			if(!vb[y]){
				q.push(y);
				vb[y] = true;
			}
		}
	}
	
}

int main(int argc, char** argv) {
	cin >> N >> M >> V;
	int x, y;
	for(int i=0; i<M; i++){
		cin >> x >> y;
		addEdge(x, y);
	}
	
	
	dfs(V);
	cout << endl;
	bfs(V);
	
	return 0;
}
