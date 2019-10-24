#include <iostream>
#include <vector>

#define S_MAX 100001

using namespace std;

vector<bool> visited(S_MAX);
vector<bool> v(S_MAX);
vector<int> s[S_MAX];
int component, temp, cnt;

void Edge(int u, int v) {
	s[u].push_back(v);
}


void dfs(int x) { 
//	temp = x;
//	if(visited[x]) return ;
	visited[x] = true;
//	component++;
	int y = s[x][0];
	
//	cout << "x: " << x <<" / y: " << y << endl;
	
	if(visited[y]){
		if(!v[y]) {
			for(int t=y; t!=x; t=s[t][0]) {
//				cout << "t: " << t << " ";
				cnt++;
			}
//			cout << "\n";
			
			cnt++;
		}
	}
	else dfs(y);
	v[x] = true;
}

int main(int argc, char** argv) {
	int T; // TC
	int n; // ÇÐ»ý ¼ö 
	int ret;
	cin >> T;
	
	for(int t=0; t<T; t++) {
		cin >> n;
		ret = n;
		
		for(int i=1; i<=n; i++) s[i].clear();
		
		fill(v.begin(), v.end(), false);
		
		for(int i=1; i<=n; i++) {
			int r;
			cin >> r;
			Edge(i, r);
		}
		cnt = 0;
		for(int i=1; i<=n; i++) {
//			printf("--- DFS --- %d \n", i);
			fill(visited.begin(), visited.end(), false);
			if(!visited[i]) dfs(i);
			
//			cout << "cnt: " << cnt << "\n";
//			if(i == temp) {
//				for(int i=1; i<=n; i++) {
//					if(visited[i] && !v[i]) {
//						v[i] = true;
//						ret--;
//					}
//				}
//				
//			}
			
//			printf("ret: %d\n", ret);
		}
		cout << n-cnt << "\n";
	}
	
	cin >> n;
	
	return 0;
}
