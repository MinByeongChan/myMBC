#include <iostream>
#include <cstring>

using namespace std;

int N, M; // N: 세로, M: 가로 
int K; //음식물 개수 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int arr[101][101] = {0, };

//DFS
int dfs(int y, int x){
	//쓰레기 위치(1)만 DFS탐색 시작
	if(arr[y][x] != 1) return 0;
	int max = 0; // DFS크기위 최대값
	arr[y][x] = 2; // 방문 표시
	printf("(%d, %d)\n", y, x); // 출력 
	for(int i=0; i<4; i++){
		int nextX = x+dx[i];
		int nextY = y+dy[i];
		dfs(nextY, nextX);
		max++;
	}
	return max;
}

int main(int argc, char** argv) {
	int r=0, c=0; //r: 세로, c: 가로 
	int result = 0;
	int temp=0;
	cin >> N >> M >> K; //입력
	//범위 초과
	if(K < 1 || K>10000 || N < 1 || M < 1) return 0;
	
	//음식물쓰레기 위치 설정(좌표)
	for(int i=0; i<K; i++){
		cin >> r >> c;
		arr[r][c] = 1;
	}
	
	//DFS실행
	for(int i=1; i<N; i++){
		for(int j=1; j<M; j++){
			if(arr[i][j] == 1){
				cout << "--- DFS ---" << endl;
				temp = dfs(i, j);
				if(result <= temp)
					result = temp;
			}
		}
	}
	//DFS크기의 최대값 출력
	cout << result << endl;
	
	return 0;
}
