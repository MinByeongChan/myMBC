#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V; // N : 노드, M : 간선, V : 시작지점 

// 벡터 초기화 
// 초기화시 벡터 공간을 여유롭게 해야한다
// 여유롭지 않으면 방문할 수 있는 노드가 제한되기 때문에 엉킴  
vector<vector<int> > a(10000); // 간선 벡터 
vector<bool> vb(1000, false); //bfs방문 
vector<bool> vd(1000, false); //dfs방문 


//간선연결 
void addEdge(int u, int v){
	a[u].push_back(v);
	a[v].push_back(u);
}

//dfs함수 
void dfs(int d){
	if(vd[d]) return;
	vd[d] = true;
	printf("%d ", d);
	for(int i=0; i<a[d].size(); i++){
		int y = a[d][i];
		dfs(y);
	}
}

//bfs함수  
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
	// 작은 숫자부터 정렬해야 하기 때문에 오름차순으로 정렬 
	for(int i=1; i<=N; i++){
		sort(a[i].begin(), a[i].end());
	}
	
	dfs(V);
	cout << endl;
	bfs(V);
	
	return 0;
}
