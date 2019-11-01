#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int edge[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
int LEN;

int NumOfEdge(string s) {
	int sum = 0;
	
	for (int i = 0; i < LEN; i++) {
		if (s.length() != LEN) {
			s += '0';
		}
	}

	sort(s.begin(), s.end());

	cout << "변환할 수: " << s << endl;
	for (int i = 0; i < LEN; i++) {
		if (s[i] == '0') {
			sum += edge[0];
		}
		else if (s[i] == '1') {
			sum += edge[1];
		}
		else if (s[i] == '2') {
			sum += edge[2];
		}
		else if (s[i] == '3') {
			sum += edge[3];
		}
		else if (s[i] == '4') {
			sum += edge[4];
		}
		else if (s[i] == '5') {
			sum += edge[5];
		}
		else if (s[i] == '6') {
			sum += edge[6];
		}
		else if (s[i] == '7') {
			sum += edge[7];
		}
		else if (s[i] == '8') {
			sum += edge[8];
		}
		else if (s[i] == '9') {
			sum += edge[9];
		}
	}
	
	return sum;
}

//
//string NumCnt(string s) {
//	int number = stoi(s);
//	string s_result = "";
//
//	number++;
//
//	string ss = to_string(number);
//
//	if (ss.length() == LEN) {
//		s_result = ss;
//		return s_result;
//	}
//	
//	else {
//		for (int i = 0; i < LEN; i++) {
//			s_result[]
//		}
//	}
//	if (0<x && x < 9) {
//		x++;
//		s_result += to_string(x);
//	}
//	else if (x == 9) {
//		s[i + 1]++;
//		s_result += to_string(0);
//		s_result += to_string()
//	}
//
//	return s_result;
//}

int main() {
	string s;
	cin >> s;

	int s_sum = 0, temp_sum = 0;
	LEN = s.length();
	s_sum = NumOfEdge(s);

	cout <<"첫 카운트 개수: "<<  s_sum << endl;

	/*for (int i = LEN*2; i < LEN*7; i++) {
		
	}*/

	int num_start = stoi(s);
	int num_end = num_start;

	while (1) {
		num_end++;
		temp_sum = NumOfEdge(to_string(num_end));
		cout << " / temp_sum: " << temp_sum << "\n";
		if (s_sum == temp_sum)
			break;
	}

	cout << num_end - num_start << endl;

	cin >> s_sum;

	return 0;
}