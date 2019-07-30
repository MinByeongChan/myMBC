#include <stdio.h>

	const int number = 4;
	int INF = 10000000;

	int a[4][4] = {
		{0, 5, INF, 8},
		{7, 0, 9, INF},
		{2, INF, 0, 4},
		{INF, INF, 3, 0}
	};

	void floydWarshall() {
		int d[number][number];
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				d[i][j] = a[i][j];
			}
		}

		// k는 거쳐가는 노드
		for (int k = 0; k < number; k++) {
			//i는 출발노드
			for (int i = 0; i < number; i++) {
				//j는 도착노드
				for (int j = 0; j < number; j++)
					if (d[i][k] + d[k][j] < d[i][j])
						d[i][j] = d[i][k] + d[k][j];
			}
		}

		//출력
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++)
				printf("%3d ", d[i][j]);
			printf("\n");
		}

	}

	int main()
	{
		floydWarshall();
	}
