#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
vector<vector<char> > arr(101);
vector<vector<char> > temp(101);
int direct[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

//같은 index를 인식하여 DFS동작
void dfs(int x, int y, char index) {
	//한번 탐색하게 되면 'X'를 집어 넣음
	arr[x][y] = 'X';

	for (int i = 0; i < 4; i++) {
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];

		//범위 제한 조건
		if (nextX < 0 || nextX > N || nextY < 0 || nextY > N)
			continue;
		
		// index가 같은 것만을 인식하여 DFS 동작
		if (arr[nextX][nextY] != 'X' && arr[nextX][nextY] == index) {
			dfs(nextX, nextY, index);
		}
	}
}

// 영역 구하기
int getArea() {

	int count = 0; // 영역의 개수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j][i] != 'X') {
				count++;
				dfs(j, i, arr[j][i]);
			}
		}
	}

	return count;
}


int main() {
	//배열의 크기
	cin >> N;

	//Init arr
	for (int i = 0; i < 101; i++) {
		arr[i].resize(101, 'X');
		temp[i].resize(101, 'X');
	}
		
	//INPUT
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp[j][i];
		}
	}

	// R,G 구분했을 때 영역 구하기
	arr = temp;
	int sol1 = getArea();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[j][i] == 'R')
				temp[j][i] = 'G';
		}
	}

	// R,G 구분하지 못했을 때 영역 구하기
	arr = temp;
	int sol2 = getArea();

	//OUTPUT
	cout << sol1 << " " << sol2;

	return 0;
}