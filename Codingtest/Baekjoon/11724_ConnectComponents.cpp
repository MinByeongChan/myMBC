#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> e[1001]; // DFS 노드를 저장
bool visited[1001]; // 방문 표시
int N, M; // N은 노드, M은 간선개수
int u, v; // u-v를 잇는 간선

//간선을 만들어주는 동작(양방햑)
void Edge(int a, int b){
	if(a<1 || b<1) return;
	e[a].push_back(b);
	e[b].push_back(a);
}

//DFS 함수
void dfs(int x){
	if(visited[x]) return ;
	visited[x] = true; // 노드가 방문 안했으면 방문표시 후 동작
	cout << x << endl;
	for(int i=0; i<e[x].size(); i++){
		int y = e[x][i];
		dfs(y);
	}
}

int main(int argc, char** argv) {
	int Cnt = 0;
	
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		cin >> u >> v;
		Edge(u, v);
		cout << "success" << endl;		
	}

	// 오름차순으로 노드를 정렬
	for(int i=0; i<1001; i++){
		sort(e[i].begin(), e[i].end());
	}
	
	// 1부터 지정 노드(N)까지 스캔
	for(int i=1; i<=N; i++){
		//방문 안한것들만
		if(!visited[i]){
			cout << " -- " << i <<" DFS -- " << endl;
			dfs(i);
			Cnt++;
		}
	}
	//출력
	cout << Cnt << endl;

	return 0;
}
