#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
	return a+b > b+a ? true : false;
}
	
string solution(vector<int> number) {
    string answer = "";
	int SIZE = number.size();
    vector<string> temp;
	
	for(int i=0; i<SIZE; i++ ) {
		string x = to_string(number[i]);
		temp.push_back(x);
	}
	
	sort(temp.begin(), temp.end(), comp);
	
	//OUTPUT
	for(int i=0; i<temp.size(); i++) {
		cout << temp[i] << " ";
	}
	cout << "\n";
	
	for(int i=0; i<SIZE; i++) {
		answer+=temp[i];
	}
	
	
	
    return answer;
}

int main(int argc, char** argv) {
	vector<int> num;
	int n;
	
	num.push_back(9);
	num.push_back(10);	
	num.push_back(6);
	num.push_back(2);
//	num.push_back(5);
	
	
	cout << solution(num) << '\n';
	cin >> n;
	
	system("pause");
	
	return 0;
}
