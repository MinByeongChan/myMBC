#include <iostream>
#include <cstring>

using namespace std;

int arr[51][51] = {0,};
int T; // 테스트 케이스
int N, M, X;
// 위,아래, 양옆 4방향마다 1인지 검사하기 위한 배열
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int x, int y){
	if(arr[x][y] != 1) return;
	
	//방문시 2로 초기화하여 재방문 X
	arr[x][y] = 2;
	//dfs호출 될때마다 4방향을 스캔
	for(int i=0; i<4; i++){
		int nextX = x+dx[i];
		int nextY = y+dy[i];
		dfs(nextX, nextY);
	}
}
	
int main(int argc, char** argv) {
	cin >> T; // 테스트 케이스의 개수 
	
	int x, y;
	//출력을 위한 배열
	int *cnt = new int[T];
	
	for(int j=0; j<T; j++){
		cin >> M >> N >> X;
		cnt[j]=0;
		
		//Case가 시작되면 배열 초기화
		for(int k=0; k<51; k++)
			memset(arr[k], 0, sizeof(int)*51);
		
		//지정한 곳에 1을 넣어줌(양배추 위치)
		for(int i=0; i<X; i++) {
			cin >> x >> y;
			if(x > M || y > N) return 0;
			arr[x][y] = 1;
		}
		
		//가로 세로 배열을 위한 2중 for문
		for(int p=0; p<M; p++){
			for(int q=0; q<N; q++){
				//스캔 도중 1이 발견되면 dfs실행
				if(arr[p][q] == 1){
					dfs(p, q);
					//유기농 벌레 cnt증가
					cnt[j]++;
				}
			}
		}
	}
	
	//출력
	for(int i=0; i<T; i++)
		cout << cnt[i] << endl;

	return 0;
}
