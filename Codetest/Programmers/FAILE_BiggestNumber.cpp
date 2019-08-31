#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//실패한 알고리즘 ㅜㅜ 
//pair에 대한 내림차순 정렬!!
//알아두자 
bool comp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first != b.first) return a.first > b.first; 
	else return a.second > b.second;
}

int first_num(int x){
	int temp = x;
	while(1){
		if( 0<temp && temp<10) break;
		temp/=10;
	}
	return temp;
}

int main() {
	vector<int> number;
	string answer = "";
	vector<pair<int, int> > result;
	
	number.push_back(3);
	number.push_back(30);
	number.push_back(34);
	number.push_back(5);
	number.push_back(9);
	
	
	int x;
	for(int i=0; i<number.size(); i++){
		x = first_num(number[i]);
		result.push_back(make_pair(x, number[i]));
	}
	
	sort(result.begin(), result.end(), comp);
	
	for(int i=0; i<result.size(); i++){
		cout << result[i].second;
	}
	
	int max = 0;
	
	for(int i=1; i<=number.size(); i++){
		if(result[i-1].first != result[i].first){
			answer += to_string(result[i-1].second);
		}
		else answer += to_string(result[i-1].second);
	}	
	
	cout << endl;
	cout << answer << endl;
	
	return 0;
}


