#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;


int main() {
	cin >> n;
	int cnt = n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str.length() == 1) continue;

		vector<char> storage;

		bool result = true;
		storage.push_back(str[0]);
		
		cout << i+1 << ": " << str << endl;

		for (int p = 1; p < str.length(); p++) {
			if (str[p - 1] == str[p]) continue;

			for (int q = 0; q < storage.size(); q++) {
				if (storage[q] == str[p]) {
					cout << str[p] << "\n";
					result = false;
					break;
				}
			}
			storage.push_back(str[p]);
		}
		if (result == false) cnt--;
		cout << cnt << "\n";
	}

	cout << cnt;

	cin >> n;
	return 0;
}