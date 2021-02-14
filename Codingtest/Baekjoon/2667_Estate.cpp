#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int component;
int arr[26][26] = { 0, };
vector<int> result; // 오름차순으로 나타내기 위한 벡터

int direct[4][2] = { 
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

void dfs(int x, int y) {
	arr[x][y] = 0; // 방문 표시
	component++; // 단지 크기 갱신

	for (int i = 0; i < 4; i++) {
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];

		// 탐색 배열이 1일 때만 동작
		if(arr[nextX][nextY] == 1)
			dfs(nextX, nextY);
	}

}
int main() {
	int N;
	cin >> N;

	//INPUT
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &arr[j][i]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j][i] == 1) {
				component = 0; 
				dfs(j, i); // dfs 동작
				result.push_back(component); // output 배열에 push_back
			}
		}
	}

	sort(result.begin(), result.end()); // 오름차순 정렬

	//OUTPUT
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) 
		cout << result[i] << "\n";
	
	return 0;
}