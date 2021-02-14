#include <iostream>
#include<vector>
#define MAX 100001
using namespace std;


int result; // 팀으로 묶인 학생의 수
vector<int> student; // 학생 배열, 각 배열값은 가리키는 지목대상이 온다.
vector<bool> visited; // 방문
vector<bool> check; // 싸이클 여부 확인 배열


void dfs(int x) {
	//처음 온 인덱스는 방문 표시
	visited[x] = true;
	
	//다음 노드를 가리킴
	int next = student[x];

	//다음 노드가 방문되었으면 싸이클 여부 확인
	if (visited[next]) {
		//방문은 했지만 싸이클 여부를 확인하지 않았다면 동작
		if (!check[next]) {
			//싸이클 여부 확인
			for (int temp = next; temp != x; temp = student[temp])
				result++;
			//자기 자신 카운트
			result++;
		}
	}
	//다음 노드를 처음 방문하면 dfs
	else dfs(next);
	//마지막으로 check로 싸이클여부까지 모두 확인했다는 표시
	check[x] = true;
}


int main() {

	int T; // TC
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N; // 학생수
		cin >> N;
		
		//Init
		student.resize(N);
		visited.resize(N + 1);
		check.resize(N + 1);

		//INPUT
		for (int i = 1; i < N+1; i++) {
			cin >> student[i];
		}

		result = 0;
		fill(visited.begin(), visited.end(), false);
		fill(check.begin(), check.end(), false);

		//DFS 동작
		for (int i = 1; i < N + 1; i++) {
			if (!visited[i])
				dfs(i);
		}
		
		//OUTPUT
		cout << N - result << endl;
	}
}