#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int SIZE; // numbers 크기

//내림차순
bool desc(int u, int v) {
	return u > v;
}

bool CheckNumber(int i, string numbers) {
	bool flag = false; // 소수 발견 안될시 바로 return
	vector<bool> visited(numbers.length());

	while(i != 0) {
		flag = false;
		int temp = i % 10;

		for (int j = 0; j < numbers.length(); j++) {
			if (temp == numbers[j] - '0' && !visited[j]) {
				flag = true;
				visited[j] = true;
				break;
			}
		}

		if (flag == false)
			return false;
		i /= 10;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	SIZE = numbers.length();
	sort(numbers.begin(), numbers.end(), desc);
	int num = stoi(numbers);

	vector<bool> temp(num + 1); // 에라토스테네스의 체 적용하기 위한 boolean 배열

	for (int i = 2; i <= num; i++) {
		if (!temp[i] && CheckNumber(i, numbers)) { // 소수이면서 각 자리수가 소수가 아닌것이 판별되면 answer++
			answer++;
		}
		//에라토스테네스의 체
		if (!temp[i]) {
			for (int j = i; j <= num; j += i) {
				temp[j] = true;
			}
		}
	}

	return answer;
}

int main() {
	string s = "011";
	cout << solution(s) << "\n";


	return 0;
}