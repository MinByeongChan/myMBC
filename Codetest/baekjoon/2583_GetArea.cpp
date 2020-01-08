#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K; // 가로, 세로, 사각형 개수
int areaCount;
bool arr[101][101] = { false, };
int direct[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // 4방향을 스캔하기 위한 방향배열

vector<int> result; // 오름차순 정렬하기 위한 결과집합

void dfs(int x, int y) {
	arr[x][y] = true;

    //DFS 동작할때마다 영역 크기를 1씩 증가
	areaCount++;
	
	for (int i = 0; i < 4; i++) {
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];

        //범위 설정 조건
		if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
			continue;

        //동서남북을 스캔후 false영역이 있다면 DFS동작 
		if (!arr[nextX][nextY]) {
			dfs(nextX, nextY);
		}
	}

}

//영역의 크기를 구함
void getArea() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!arr[j][i]) {
				areaCount = 0;
				dfs(j, i);

				result.push_back(areaCount);
			}
		}
	}
}

int main() {
	//INPUT
	cin >> N >> M >> K;


	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; 
		
		// 사각형 범위 설정
		for (int p = y1; p < y2; p++) {
			for (int q = x1; q < x2; q++) {
				if(!arr[q][p]) arr[q][p] = true;
			}
		}
	}
    
    
	getArea();
	
	//출력을 위해 오름차순 정렬
	sort(result.begin(), result.end());
	
	//OUTPUT
	int result_size = result.size();
	cout << result_size << "\n";
	for (int i = 0; i < result_size; i++)
		cout << result[i] << " ";
	

}