#include <vector>
#include <iostream>
#include <string.h>
#define MAX 100001
using namespace std;

int direct[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
//int **arr;
vector<vector<int>> arr;
int cnt;

//dfs�� �̿��� ���� �׷��� Ȯ�� 
void dfs(int y, int x, int n) {	
	if(arr[y][x] != n) return ;
	arr[y][x] = 0;
	
	//��,�Ʒ�,�翷�� ��� Ȯ�� 
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

//���α׷��ӽ����� &picture�� �ȵǼ� ��ǰ...
//�����Ҵ翡 ������ �ִ°� ������ �ذ��� ���� 
vector<int> solution(int m, int n, vector<vector<int>> &picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer;
    //2���� ���� �������� �Ҵ� 
    arr.assign(m+1, vector<int>(n,0));
	
	//���������� 2���� ���Ϳ� picture�迭�� �ʱ�ȭ  
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			arr[j][i] = picture[j][i];
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
	//a to z ���� ������ ��ĵ 
    for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cnt = 0;
			cout << arr[j][i] << " ";
			//����ִ� ������ 0���� �ν�
			//0�� �ƴѰ��� �ɸ� 
			if(arr[j][i] != 0) {
				int a = arr[j][i];
				//���� ��ġ�� dfs�������� ī��Ʈ 
				cnt++;
				//���� ���ڿ��� �ٸ� �׷����� ������ �ٸ� �׷����� �ν� 
				//���� ���� ������� ��� �׷��� �ν� 
				number_of_area++;
				dfs(j, i, a);
				//��� cnt�� �ִ밪�� ���� 
				if(cnt > max_size_of_one_area) max_size_of_one_area = cnt;
			}
		}
		cout << endl;
	}
	
    //��� 
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
