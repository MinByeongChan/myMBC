#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M; // N : row M : column
int arr[101][101] = {-1, }; // 초기값은 -1로 초기화  
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int> > q;
int cnt = 0;
vector<int> result;
int min =0;

void bfs(int x, int y){
	cnt++;
	int nextX;
	int nextY;
	//상하좌우 검사 시작
	for(int i=0; i<4; i++){
		nextX = x+dx[i];
		nextY = y+dy[i];
		
		// 도착? 
		if(nextX == N-1 && nextY == M-1){
			q.push(make_pair(nextX, nextY));
			result.push_back(q.size());
			return ;
		}
		//각 케이스를 검사 
		if(arr[nextX][nextY] == 1){
			q.push(make_pair(nextX, nextY));
			arr[nextX][nextY] = 2;
			bfs(nextX, nextY);
		}
	}
	//x가 범위 초과시	
	if(nextX > M-1 ){
		q.pop();
		arr[q.back().first][q.back().second] = 2;
		bfs(q.back().first-1, q.back().second);
	}
	//y가 범위 초과시 
	if(nextY > N-1){
		q.pop();
		arr[q.back().first][q.back().second] = 2;
		bfs(q.back().first, q.back().second-1);
	}
}

int main(int argc, char** argv) {
	
	cin >> N >> M;
	
	//입력 받기위한 string
	string st[N+1];
	for(int i=0; i<N; i++){
		cin >> st[i];
	}

	//문자형을 int로 변환해주기 위한 과정 
 	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arr[i][j] = st[i].at(j);
			//ASCII로 49는 1, 48은 0으로 치환하여 arr(int)배열에 대입 
			if(arr[i][j] == 49) arr[i][j] = 1;
			if(arr[i][j] == 48) arr[i][j] = 0;
		}
 	}
 	
 	//시작은 q에 푸시 
 	q.push(make_pair(0, 0)); // 시작!
	arr[0][0] = 2; //방문 표시
	//시작 이후의 인덱스 탐색 시작 
	bfs(0,0);
	int min = 100000;
	
	//loop문이 계속 동작하기 때문에 최소값을 최신화 
	for(int i=0; i<result.size(); i++){
		if( min >= result[i])
			min = result[i];
	}
	cout << min << endl;
	return 0;
}
