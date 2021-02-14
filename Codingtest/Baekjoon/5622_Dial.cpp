#include <iostream>
#include <string>
using namespace std;

string st;
int LEN;
int result=0;

int Check(const char s) {
	if (65 <= s && s <= 67) {
		return 3;
	}
	else if (68 <= s && s <= 70) {
		return 4;
	}
	else if (71 <= s && s <= 73) {
		return 5;
	}
	else if (74 <= s && s <= 76) {
		return 6;
	}
	else if (77 <= s && s <= 79) {
		return 7;
	}
	else if (80 <= s && s <= 83) {
		return 8;
	}
	else if (84 <= s && s <= 86) {
		return 9;
	}
	else if (87 <= s && s <= 90) {
		return 10;	
	}
	else if(s > 90){
		return 11;
	}
	else {
		return 2;
	}
}

int main() {
	cin >> st;
	LEN = st.length();

	for (int i = 0; i < LEN; i++) {
		result += Check(st[i]);
	}
	cout << result;

	cin >> st;

	return 0;
}