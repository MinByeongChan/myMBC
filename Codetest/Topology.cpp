#include <iostream>
#include<queue>
#include<vector>
#define MAX 10

using namespace std;

int n, inDegree[MAX]; // 진입차수
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;

	//진입차수 0인 노드 찾기
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	//정렬이 완전히 수행되려면 정확히 n개의 노드를 수행 -> 사이클 발생시 종료
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			printf("사이클 발생\n");
			return;
		}
		int x = q.front();
		q.pop();
		result[i-1] = x;
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);
}


int main()
{
	n = 7;
	a[1].push_back(2);
	inDegree[2]++; 
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;

	topologySort();
	return 0;
}
