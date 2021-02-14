#include<iostream>
#include<queue>
#define INF 10000000
using namespace std;

int main() {
	int N, mn = INF;
	cin >> N;
	
	int rgb[1001][3];
	queue<int> q;
	int st[3];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rgb[i][j];
		}
	}

	if (N == 3) {
		for (int i = 0; i < 3; i++) {
			q.push(rgb[0][i]);
			
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
			}
		}
	}
	else {


	}
	




	return 0;
}