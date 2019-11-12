#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

class Member {
public:
	int n;
	int age;
	string name;
	vector<pair<int, string> > mem;
	vector<int> idx;

	Member() : n(1){
		mem.resize(1);
	}
	Member(int n1) : n(n1) {
		mem.resize(n1);
	}
	void set() {
		for (int i = 0; i < n; i++) {
			cin >> mem[i].first >> mem[i].second;
		}
	}
	
	
	void print() {
		for (int i = 0; i < n; i++) {
			cout << mem[i].first << " " << mem[i].second << "\n";
		}
	}
};

bool cmp(pair<int, string> u, pair<int, string> v) {
	return u.first < v.first;
}

int main(int argc, char** argv) {
	int age; //나이
	string name; //이름
	int n; //회원 수 

	cin >> n;

	Member member(n);
	member.set();

	sort(member.mem.begin(), member.mem.end(), cmp);
	
	member.print();

	//case 2
	//vector<pair<int, string> > mem(n);

	////INPUT
	//for (int i = 0; i < n; i++) {
	//	cin >> mem[i].first >> mem[i].second;
	//}
	//
	//stable_sort(mem.begin(), mem.end(), cmp);

	////OUTPUT
	//for (int i = 0; i < n; i++) {
	//	cout << mem[i].first << " " << mem[i].second << "\n";
	//}

	cin >> n;

	return 0;
}
