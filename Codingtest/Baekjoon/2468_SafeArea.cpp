#include<iostream>
#define INF 101
using namespace std;


int arr[101][101] = { 0, }; 
bool visited[101][101]; // 방문 배열
int direct[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int N, mn = INF, mx = 0; // 배열 크기. 최소, 최대 빗물의 높이
int result = 1; // 빗물에 모두 잠기는 경우는 없다는 조건으로 1

void dfs(int x, int y, int idx) {
	//탈출 조건
	if(visited[x][y]) return;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];

		//범위 제한 조건
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
			continue;

		if (arr[nextX][nextY] > idx) {
			//printf("( %d, %d )\n", nextX, nextY);
			dfs(nextX, nextY, idx);
		}
	}
}

void getCount(int idx){
	int count = 0; // 영역의 크기

	fill(&visited[0][0], &visited[100][100], false);

	//cout << "mn : " << idx << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j][i] > idx && !visited[j][i]) {
				count++;
				dfs(j, i, idx);
			}
			//cout << visited[j][i] << " ";
		}
		//cout << "\n";
	}

	//cout <<"Count : " <<  count << "\n";
	//최대 안전 영역 갱신
	if (result < count)
		result = count;
}

int main() {
	cin >> N;

	//INPUT
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[j][i];
			//빗물의 최대, 최소 높이 구하기
			if (arr[j][i] < mn) mn = arr[j][i];
			if (arr[j][i] > mx) mx = arr[j][i];
		}
	}

	// 최소부터 최대까지 모두 스캔
	// 단 최대는 항상 0이 나오므로 의미가 없다.
	for (int i = mn; i < mx; i++) 
		getCount(i);

	//OUTPUT
	cout << result;


	return 0;
}