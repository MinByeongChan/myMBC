#include <iostream>
#include <string>
using namespace std;

int result[26];
char alpha[26] = { 
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y', 'z'
};

int main() {
	string S;
	cin >> S;
	fill(result, result + 26, -1);

	int LEN = S.length();

	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < 26; j++) {
			if (S[i] == alpha[j] && result[j] == -1) {
				result[j] = i;
				break;
			}
		}
		
	}

	for (int i = 0; i < 26; i++) {
		cout << result[i] << " ";
	}
	
	cin >> S;



	return 0;
}