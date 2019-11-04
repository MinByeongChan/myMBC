#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string S;
	vector<pair<int, char> > result;
	cin >> S;
	//입력 문자열의 길이
	int LEN = S.length();
	int max = 0, cnt=0;
	//정렬
	
	for (int i = 0; i < LEN; i++) {
		if (S[i] >= 97) S[i] -= 32;
	}

	sort(S.begin(), S.end());

	for (int i = 0; i < LEN; i++) {
		cout << S[i] << " ";
	}
	cout << "\n";

	
	for (int i = 0; i < LEN; i++) {
		char x = S[i];
		cnt = 1;
		
		cout << i << " / " << x << " ";
		for (int j = i+1; j < LEN; j++) {
			cout << S[j] << " ";
			if (x == S[j])
				cnt++;
			
			else {
				i = j-1;
				break;
			}
		}
		if (cnt >= max) {
			max = cnt;
			result.push_back(make_pair(max, x));
		}
		cout << "\n";
	}

	int a = 0;
	for (int i = 0; i < result.size(); i++) {
		if (result[i].first == max) {
			a++;
		}
		if (a > 1) {
			cout << "?";
			return 0;
		}
	}
		
	if(a == 1)
		cout << result.back().second;

	cin >> S;


	return 0;
}