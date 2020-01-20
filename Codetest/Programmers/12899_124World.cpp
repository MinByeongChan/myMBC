#include<iostream>
#include<string>
using namespace std;


string solution(int n) {
	string answer = "";
	int x = 0;
	int remainder = 0;

	while (n != 0) {

		if (n % 3 == 0) {
			n = (n / 3) - 1;
			answer.insert(0, "4");
		}
		else {
			answer.insert(0, to_string(n % 3));
			n /= 3;

		}

	}

	return answer;
}


int main() {
	int n = 500000000;
	cout << solution(n);

	return 0;
}