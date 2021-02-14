#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	long long int sum = 0;
	cin >> s;

	string temp_st = "";
	int total_temp = 0;
	int SIZE = s.length();
	int i;
	
	for (i = 0; i < SIZE; i++) {
		if (s[i] == '-') {
			break;
		}
		else if (s[i] == '+') {
			total_temp += stoi(temp_st);
			temp_st = "";
		}

		else {
			temp_st += s[i];
		}
	}

	total_temp += stoi(temp_st);
	sum = total_temp;
	temp_st = "";
	
	for ( int j = i+1; j < SIZE; j++) {
		if (s[j] == '+' || s[j] == '-') {
			sum -= stoi(temp_st);
			temp_st = "";
		}

		else {
			temp_st += s[j];
		}

	}

	if(temp_st != "") 
		sum -= stoi(temp_st);
	
	
	cout << sum ;

	cin >> s;

	return 0;
}