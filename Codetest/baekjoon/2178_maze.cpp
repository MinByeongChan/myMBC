#include <iostream>
#include <queue>
#include <utility>
#define MAX 1000000
using namespace std;

int N, M;
int arr[101][101];
int direct[4][2] = { {1, 0}, {0, 1}, {0, -1} , {-1,0} };

int minValue = MAX;

//DFS�� Ǯ��
//�׽�Ʈ ���̽� ���� �������� ȿ������ �������� ���� üũ�� �ȵ�

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

//BFS�� ���� Ǯ��
void bfs() {
	queue<pair<int, int> > q;
	
	//�ʱⰪ (0,0)���� ����
	q.push(make_pair(0, 0));
	
	while (!q.empty()) {
		int currX = q.front().first;
		int currY = q.front().second;
		//�ѹ� �õ��� ������ q�� pop
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			//�������� 4������ ��ĵ
			int nextX = currX + direct[i][0];
			int nextY = currY + direct[i][1];

			//�� �õ����� �� ��ǥ�� ������ 1�� ������
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

	//DFS(x��, y��, ī��Ʈ �ʱⰪ)
	//dfs(0, 0, 0);
	//cout << minValue;

	//BFS
	bfs();

	//�� �õ����� ���� ������ 1�� �����ִ� ������� �ذ�
	//�ᱹ ������ �ε����� M-1, N-1�� ���ϸ� �ּҰŸ� ����
	cout << arr[M - 1][N - 1];

	cin >> N;

	return 0;
}