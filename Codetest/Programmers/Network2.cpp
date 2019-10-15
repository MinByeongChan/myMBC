#include <string>
#include <vector>
#include <iostream>

#define COM_MAX 200

using namespace std;

bool visited[200] = {false, };

void dfs(int x, int n, vector<vector<int> > &computers) {
	visited[x] = true;
	
	for(int i=0; i<n; i++) {
		if(!visited[i] && computers[x][i] == 1 ) {
			dfs(i, n, computers);
		}
	}
	
}


int solution(int n, vector<vector<int> > computers) {
    int result = 0;
    
	//solution 1
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			dfs(i, n, computers);
		}
	}
	
	
	
	return result;
}


int main(int argc, char** argv) {
	int n = 5;
	vector<vector<int>>com{
		{1,1,0,0,0}, 
		{1,1,0,1,0}, 
		{0,0,1,0,1},
		{0,1,0,1,1},
		{0,0,1,1,1}
	};

	cout << "result: " << solution(n, com);	

	cin >> n;
	
	return 0;
}
