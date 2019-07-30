#include <stdio.h>

int number = 6;
int INF = 10000000;

// 전체 그래프를 초기화.
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
}; // 노드간의 거리를 의미

bool v[6]; // 방문한 노드!
int d[6]; // 노드간 거리

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i]; // 최단거리를 의미
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++)
		d[i] = a[start][i];
	v[start] = true;

	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j])
					d[j] = d[current] + a[current][j];
			}
		}
	}
}
int main()
{
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}
