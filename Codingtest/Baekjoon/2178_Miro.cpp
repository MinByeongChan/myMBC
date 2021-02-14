#include<iostream>
#include<vector>
#include<queue>
#include <utility>
using namespace std;


class Gragh {
public:
	int n, m; //세로, 가로
	int cnt; // 최소 길이 수
	int direct[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} }; // 방향 배열
	int arr[101][101] = { 0, };

	Gragh() : n(0), m(0) {};
	Gragh(int n1, int m1) : n(n1), m(m1) {
		//INPUT
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf_s("%1d", &arr[j][i]);
			}
		}
	};

	//BFS 함수
	void bfs() {
		queue<pair<int, int>> q; // x,y좌표를 나타내기위해 pair사용
		q.push(make_pair(0,0));
		
		cnt = 1;
		
		while (!q.empty()) {
			
			int qSize = q.size(); // queue의 깊이

			for (int i = 0; i < qSize; i++) {
				int x = q.front().first;
				int y = q.front().second;

				q.pop();

				for (int i = 0; i < 4; i++) {

					int nextX = x + direct[i][0];
					int nextY = y + direct[i][1];

					if (nextX > m || nextY > n || nextX < 0 || nextY < 0)
						continue;

					if (arr[nextX][nextY] != 1)
						continue;

					// 마지막 인덱스에 도달하면 return
					if (nextX == m - 1 && nextY == n - 1)
						return;

					q.push(make_pair(nextX, nextY));
					arr[nextX][nextY] = 0;
				}
			}
			cnt++;
		}
		
	}
};



int main() {
	int N, M;
	cin >> N >> M;
	
	Gragh G(N, M);

	G.bfs();

	// 마지막 인덱스는 카운트 하지 않고 넘어가므로 +1
	cout << G.cnt +1;
		

	return 0;
}



