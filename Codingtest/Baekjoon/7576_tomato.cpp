#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int tomato[1001][1001] = {0, };
int direct[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int nextX, nextY;


//미완성
void bfs(int x, int y) {
	int day = 0;
	int currX = x;
	int currY = y;
	queue<pair<int, int> > q;

	//시작은 등록하고 반복문 동작 
	q.push(make_pair(currX, currY));
	tomato[currX][currY] = 1;

	while (!q.empty()) {
		currX = q.front().first;
		currY = q.front().second;

		q.pop();
		printf("(%d, %d)\n", currX, currY);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << tomato[j][i] << " ";
			}
			cout << "\n";
		}

		for (int i = 0; i < 4; i++) {
			nextX = currX + direct[i][0];
			nextY = currY + direct[i][1];

			if (nextX >= M || nextX < 0 || nextY >= N || nextY < 0) 
				continue;

			if (tomato[nextX][nextY] == 0) {
				tomato[nextX][nextY] = 1;
				q.push(make_pair(nextX, nextY));
			}
		}
		day++;
	}
	cout << "DAY : " << day;
}
int main(int argc, char** argv) {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &tomato[j][i]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[j][i] == 1) {
				bfs(j, i);
			}
		}
	}

	cin >> N;

	return 0;
}