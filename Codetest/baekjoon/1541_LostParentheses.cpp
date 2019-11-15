#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	long long int sum = 0;
	cin >> s;

	string temp_st = "";
	int total_temp = 0;
	int num_len = 1;
	int minus = 0;
	for (int i = 0; i < s.length(); i++) {
		
		if (s[i] == '-') {
			total_temp += stoi(temp_st);
			//cout << "total: " << total_temp << "\n";
			if (minus == 0) {
				//기존에 스캔했던 데이터를 sum에 더함
				sum += total_temp;
				minus = 1;
			}
			else if(minus == 1) {
				sum -= total_temp;
				minus = 0;
			}
			
			num_len = 1;
			total_temp = 0;
			temp_st = "";
		}
		else if (s[i] == '+') {
			total_temp += stoi(temp_st);
			num_len = 1;
			temp_st = "";
		}

		else {
			temp_st += s[i];			
		}

	}
	total_temp += stoi(temp_st);
	sum -= total_temp;
	
	
	cout << sum ;

	cin >> s;

	return 0;
}