#include <iostream>
#include <string>
using namespace std;


string Check(string S) {
	int cnt_temp = 0;
	int LEN = S.length();

	for (int i = LEN - 1; i >= 0; i--) {
		if (S[i] == ' ')
			cnt_temp++;
		else break;
	}
	
	//cout << cnt_temp << "\n";

	if (cnt_temp > 0)
		return S.substr(0, LEN - cnt_temp);
	else return S;
}

int main() {
	string S;
	int LEN, cnt = 0;

	//������� �����ؼ� �Է¹޴� �Լ�
	getline(cin, S);

	int i = 0;

	S = Check(S);

	if (S[0] == ' ')
		i += 1;

	//�Է� ���ڿ� ����
	LEN = S.length();
	
	for (int i = 0; i < LEN; i++) {
		if (S[i] != ' ') {
			cnt++;
			break;
		}
	}

	int state = 0;
	while (i != LEN) {
		if (S[i] != ' ' && state == 0)
			state = 1;

		if (S[i] == ' ' && state == 1 ) {
			cnt++;
			state = 0;
		}
		i++;
	}

	cout << cnt;

	cin >> LEN;

	return 0;
}