#include <iostream>

using namespace std;

int arr[51][51] = {0, };
int N,M, cnt, loop;

void dfs(int c, int r, int d) {
	
	int d_temp = d;
	
	if(arr[c][r] == 0) {
		cnt++;
		arr[c][r] = 2;
	}
	
	for(int i=0; i<4; i++) {
		int nextX = r;
		int nextY = c;
		
//		printf("x: %d / y: %d, d: %d\n", nextX, nextY, d_temp);
//		cout << "cnt: "<< cnt << "\n";
		d_temp--;
		if(d_temp<0) d_temp=3;
		
		if(d_temp==0) {
			nextX--;
		}
		else if(d_temp==1){
			nextY++;
		} 
		else if(d_temp==2){
			nextX++;
		}
		else if(d_temp==3) {
			nextY--;
		}
		
		if(arr[nextY][nextX] == 0) {
			dfs(nextY, nextX, d_temp);
		}
	}
		
		
}

int main(int argc, char** argv) {
	int r,c,d;
	
	cin >> N >> M; // INPUT ROW, COL
	
	//r,c : 로봇의 위치 / d: 로봇이 바라보는 방향 
	// d : 0 = N / 1=E / 2=S / 3=W 
	cin >> r >> c >> d;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> arr[j][i];
		}
	}
	
	//청소하는 칸의 개수 
	cnt = 0;
	
	dfs(c,r,d);
	
	
	cout << cnt << "\n";
	cin >> N;

	return 0;
}
