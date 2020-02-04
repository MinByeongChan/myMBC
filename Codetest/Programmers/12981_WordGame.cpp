#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> result;

bool is_right(string word) {
	int Size = result.size();

	for (int i = 0; i < Size; i++) {
		if (result[i] == word)
			return false;
	}

	return true;
}

bool checkWord(string word) {

	int Size = result.size();
	string s = result.back();
	if (s.back() != word[0]){
		return false;
	}
	return true;
}

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);
	
	int Size = words.size();
	int person = 0;
	int turn = 1;

	result.push_back(words[0]);

	for (int i = 1; i < Size; i++) {
		person = (i % n) + 1;
	
		cout << person << " " << turn << "\n";
		
		if (is_right(words[i]) && checkWord(words[i])) {
			cout << words[i] << "\n";
			result.push_back(words[i]);
		}
		else {
			answer[0] = person;
			answer[1] = turn;
			break;
		}

		if ((person) % n == 0)
			turn++;
	}


	return answer;
}

int main() {
	vector<string> words{ "hello", "one", "even", "never", "now", "world", "draw" };
	int n = 2;

	vector<int> result = solution(n, words);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << "\n";
    
	return 0;
}