#include <vector>
#include <iostream>
#include <string.h>
#define MAX 100001
using namespace std;

int direct[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
//int **arr;
vector<vector<int>> arr;
int cnt;

//dfs를 이용해 인접 그래프 확인 
void dfs(int y, int x, int n) {	
	if(arr[y][x] != n) return ;
	arr[y][x] = 0;
	
	//위,아래,양옆을 모두 확인 
	for(int i=0; i<4; i++){
		int nextX = x + direct[i][0];
		int nextY = y + direct[i][1];
		if(nextX < 0 || nextY < 0) continue;
		if(arr[nextY][nextX] == n){
			cnt++;
		}
		dfs(nextY, nextX, n);
	}
}

//프로그래머스에서 &picture가 안되서 못품...
//동적할당에 문제가 있는것 같은데 해결을 못함 
vector<int> solution(int m, int n, vector<vector<int>> &picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer;
    //2차원 벡터 동적으로 할당 
    arr.assign(m+1, vector<int>(n,0));
	
	//전역변수인 2차원 벡터에 picture배열값 초기화  
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			arr[j][i] = picture[j][i];
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
	//a to z 까지 데이터 스캔 
    for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cnt = 0;
			cout << arr[j][i] << " ";
			//비어있는 영역은 0으로 인식
			//0이 아닌곳을 걸름 
			if(arr[j][i] != 0) {
				int a = arr[j][i];
				//현재 위치는 dfs들어가기전에 카운트 
				cnt++;
				//같은 숫자여도 다른 그래프상에 있으면 다른 그래프로 인식 
				//같은 숫자 상관없이 모든 그래프 인식 
				number_of_area++;
				dfs(j, i, a);
				//결과 cnt의 최대값을 저장 
				if(cnt > max_size_of_one_area) max_size_of_one_area = cnt;
			}
		}
		cout << endl;
	}
	
    //출력 
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    
    printf("%d %d", answer[0], answer[1]);
    
}

int main() {
	int m = 6;
	int n = 4;
	vector<vector<int>> picture{
		{1,1,1,0}, {1,2,2,0}, {1,0,0,1}, 
		{0,0,0,1}, {0,0,0,3}, {0,0,0,3}
	};
		
	solution(m, n, picture);    

    return 0;
}
