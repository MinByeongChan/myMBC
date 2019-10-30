#include <iostream>
#include <queue>
#include <utility>
#define MAX 1000000
using namespace std;

int N, M;
int arr[101][101];
int direct[4][2] = { {1, 0}, {0, 1}, {0, -1} , {-1,0} };

int minValue = MAX;

//DFS로 풀이
//테스트 케이스 답은 나오지만 효율성이 문제인지 정답 체크가 안됨

void dfs(int x, int y, int cnt) {
	
	if (arr[x][y] == 0) return ;

	if (x >= M - 1 && y >= N - 1) {
		if (cnt < minValue) {
			minValue = cnt+1;
			return ;
		}
	}
	arr[x][y] = 0;
	/*cout << "cnt : " << cnt << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[j][i] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < 4; i++) {
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];

		if (arr[nextX][nextY] == 1) {
			dfs(nextX, nextY, cnt+1);
		}
	}
}

//BFS로 문제 풀이
void bfs() {
	queue<pair<int, int> > q;
	
	//초기값 (0,0)으로 설정
	q.push(make_pair(0, 0));
	
	while (!q.empty()) {
		int currX = q.front().first;
		int currY = q.front().second;
		//한번 시도할 때마다 q를 pop
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			//동서남북 4방향을 스캔
			int nextX = currX + direct[i][0];
			int nextY = currY + direct[i][1];

			//매 시도마다 전 좌표의 값에서 1을 더해줌
			if (arr[nextX][nextY] == 1 && nextX < M && nextY < N) {
				q.push(make_pair(nextX, nextY));
				arr[nextX][nextY] = arr[currX][currY] + 1;
			}
		}
	}
}


int main() {
	//INPUT
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &arr[j][i]);
		}
	}

	//DFS(x값, y값, 카운트 초기값)
	//dfs(0, 0, 0);
	//cout << minValue;

	//BFS
	bfs();

	//매 시도마다 전에 값에서 1을 더해주는 방식으로 해결
	//결국 마지막 인덱스인 M-1, N-1을 구하면 최소거리 산정
	cout << arr[M - 1][N - 1];

	cin >> N;

	return 0;
}