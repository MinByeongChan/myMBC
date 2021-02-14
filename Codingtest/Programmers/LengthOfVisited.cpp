#include<string>
#include <iostream>
using namespace std;


int solution(string dirs) {

	int result = 0;
	bool arr[11][11][11][11] = { false, } ; // 탐색 전 x, 탐색 전 y, 탐색 후 x, 탐색 후 y 
	int x = 5; int y = 5;
	int len = dirs.length();

	for (int i = 0; i < len; i++) {
			if (dirs[i] == 'U' && y < 10) {
				if (!arr[x][y][x][y+1]) {
					arr[x][y][x][y+1] = true;
					arr[x][y+1][x][y] = true;
					result++;
				}
				y++;
			}
			else if (dirs[i] == 'R'&& x < 10) {
				if (!arr[x][y][x+1][y]) {
					arr[x][y][x+1][y] = true;
					arr[x+1][y][x][y] = true;
					result++;
				}
				x++;

			}
			else if (dirs[i] == 'D'&& y > 0) {
				if (!arr[x][y][x][y-1]) {
					arr[x][y][x][y-1] = true;
					arr[x][y-1][x][y] = true;
					result++;
				}
				y--;

			}
			else if (dirs[i] == 'L'&& x > 0) {
				if (!arr[x][y][x-1][y]) {
					arr[x][y][x-1][y] = true;
					arr[x-1][y][x][y] = true;
					result++;
				}
				x--;

			}
	
	}

	return result;
}


int main() {
	string s = "LURDLURDLURDLURDRULD";

	cout << solution(s);

	return 0;
}