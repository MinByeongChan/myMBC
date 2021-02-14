#include <iostream>

using namespace std;

int arr[16][16] = {0, };
int direct[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int cntX=0, cntY=0;

int dfs(int b, int a) {
	int nextY = b + 1;
	int nextX = a + 1;
	
	if(arr[nextY][a] == 0) return cntY;
	if(arr[nextY][a] == 1){
		cntY++;
		dfs(nextY, a);
	}	
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++) {	
		int result = 0;
		int N, K; //N : 행령 크기, K :2단어길이
		cin >> N >> K; // INPUT
			
		for(int x=0; x<N; x++) {
			for(int y=0; y<N; y++) {
				cin >> arr[y][x];
			}
		} 
		
//		cout << endl;
//		//배열 출력 
//		for(int x=0; x<N; x++) {
//			for(int y=0; y<N; y++) {
//				cout << arr[y][x] << " ";
//			}
//			cout << endl;
//		}
		
		for(int x=0; x<N; x++) {
//			printf("------ x : %d ------\n", x);
			cntY=0;	
			for(int y=0; y<N; y++) {
				if(arr[y][x] == 0) {
					cntY = 0;
					continue;
				}
				if(arr[y][x] == 1){
					cntY++;
				}
				if(cntY == K && arr[y+1][x] == 0) {
					cntY = 0;
					result++;
//					printf("result : %d\n", result);
				}
			}
		}
		
		//배열 출력 
//		for(int y=0; y<N; y++) {
//			for(int x=0; x<N; x++) {
//				cout << arr[y][x] << " ";
//			}
//			cout << endl;
//		}
		
		for(int y=0; y<N; y++) {
//			printf("------ y : %d ------\n", y);
			cntX=0;	
			for(int x=0; x<N; x++) {
				if(arr[y][x] == 0) {
					cntX = 0;
					continue;
				}
				if(arr[y][x] == 1){
//					printf("(%d, %d)\n", y, x);
					cntX++;
				}
				
				if(cntX == K && arr[y][x+1] == 0) {
					cntX = 0;
					result++;
//					printf("result : %d\n", result);
				}
			}
		}
		
		
		cout << "#" << t<<" "<< result << endl;
				
	}
	
	cin >> T;
	
	return 0;
}
