#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, mn = 1000000;
char temp[2] = { 'W', 'B' };
//string board[51];
vector<string> board(51);

int Check(char x) {
	vector<string> temp_board(board);
	temp_board[0][0] = x;
	int cnt = 0;
	cout << "--- temp_board ---\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << temp_board[i][j];
		 }
		cout << "\n";
	}

	cout << "\n" << temp_board[0][0];

	for (int i = 1; i < M; i++) {
		if(temp_board[0][i - 1] == temp_board[0][i]) {
			if (temp_board[0][i] == 'W')
				temp_board[0][i] = 'B';
			else
				temp_board[0][i] = 'W';
			cnt++;
		}
		cout << temp_board[0][i];
	}
	cout << "\n";

	for (int i = 1; i < N; i++){
		for (int j = 0; j < M; j++) {
			if (temp_board[i-1][j] == temp_board[i][j]) {
				if (temp_board[i][j] == 'W')
					temp_board[i][j] = 'B';
				else
					temp_board[i][j] = 'W';
				cnt++;
			}
			cout << temp_board[i][j];
		}
		cout << "\n";
	}

	return cnt;
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	
	for (int i = 0; i < 2; i++) {
		int ct = Check(temp[i]);

		cout << ct << "\n";

		if (ct <= mn)
			mn = ct;
	}

	cout << mn;

	cin >> N;


	return 0;
}