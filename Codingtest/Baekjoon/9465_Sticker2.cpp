#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int T, n;
int score[2][MAX], dp[MAX][3];

int sticker(int c, int status){
	if(c == n) return 0;
	//메모이제이션 
	if(dp[c][status] != -1) return dp[c][status];
	
	//첫result(최대값) 초기화 
	int result = sticker(c+1, 0);
	
	//지그재그로 최댓값을 최신화 
	//status(1,2)에 따라 지그재그로 이동하며 최댓값 갱신 
	if(status != 1) result = max(result, sticker(c+1, 1) + score[0][c]);
	if(status != 2) result = max(result, sticker(c+1, 2) + score[1][c]);
	
	//dp배열 갱신 
	dp[c][status] = result;	
	return result;
}

int main(int argc, char** argv) {
	cin >> T; // 테스트케이스 
	for(int t=0 ; t<T; t++){
		cin >> n;
		//점수 배열 초기화 
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin >> score[i][j];
			}		
		}
		//dp배열 -1로 초기화 
		for(int i=0; i<n; i++)
			for(int j=0; j<3; j++)
				dp[i][j] = -1;
		cout << sticker(0, 0) << endl;
	}

	return 0;
}
