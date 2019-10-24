#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int component;
int arr[26][26] = { 0, };
vector<int> result;

int direct[4][2] = { 
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

void dfs(int x, int y) {
//	if (arr[x][y] == 0) return;
	arr[x][y] = 0;
	component++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];

		if(arr[nextX][nextY] == 1)
			dfs(nextX, nextY);
	}

}
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &arr[j][i]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j][i] == 1) {
				component = 0;
				dfs(j, i);
				result.push_back(component);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	cin >> N;
	return 0;
}