#include <iostream>
#include <vector>
using namespace std;

class Gragh {
public:
	int n, m;
	vector<vector<int> > arr; //이중벡터로 선언

	// 보조생성자
	Gragh(int m1, int n1): m(m1), n(n1){
		arr.resize(m+1);
		for (int i = 0; i < m+1; i++) {
			arr[i].resize(n+1);
		}
	};

	int dfs(int x, int y) {
		int direct[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
		int size = 1; // 사이즈 증감자

		arr[x][y] = 0; // 노드를 방문했다고 표시

		for (int i = 0; i < 4; i++) {
			int nextX = x + direct[i][0];
			int nextY = y + direct[i][1];

			if (nextX < 1 || nextX > m || nextY < 1 || nextY > n)
				continue;

			//영역을 탐색하면서 1인 경우는 size를 1씩 증가시킴
			if (arr[nextX][nextY] == 1) {
				size += dfs(nextX, nextY);
			}
				
			
		}

		//영역의 size 반환
		return size;
	}

	int maxArea() {
		int mx = 0; // 최대값

		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < m+1; j++) {
				//arr이 1일때만 동작
				if (arr[j][i] == 1) {
					//dfs동작
					int tmpArea = dfs(j, i);

					//최대값 갱신
					if ( tmpArea > mx ) {
						mx = tmpArea;
					}
				}
			}
		}

		return mx;
	}

};



int main(int argc, char** argv) {
	int N, M, K; // 세로, 가로, 음식물 개수 

	//INPUT
	cin >> N >> M >> K; 
	if(K < 1 || K>10000 || N < 1 || M < 1) return 0;
	
	Gragh G(M, N);

	for(int i=0; i<K; i++){
		int r, c;
		cin >> r >> c;
		G.arr[c][r] = 1;
	}
	
	//OUTPUT
	cout << G.maxArea() << "\n";

	return 0;
}
