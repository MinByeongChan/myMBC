#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//string 짜증나는구만
 
int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N, M;
		string s;
		vector<pair<int, string>> v;
		
		cout << "#";
		cin >> N >> M;
		cin >> s;
		
		int S_LEN = s.size();
		
		string temp;
		string a = "";
		for(int i=0; i<S_LEN; i++) {
			
			if(s[i] == ' ') {
				cout << "띄어쓰기" <<endl;
				temp = "";
				continue;
			}
			
			if(T_LEN == 3){
				
				if(temp == "ZRO"){
					v.push_back(make_pair(0, "ZRO"));
				}
				if(temp == "ONE"){
					v.push_back(make_pair(1, "ONE"));
				}
				if(s == "TWO"){
					v.push_back(make_pair(2, "TWO"));
				}
				if(s == "THR"){
					v.push_back(make_pair(3, "THR"));
				}
				if(s == "FOR"){
					v.push_back(make_pair(4, "FOR"));
				}
				if(s == "FIV"){
					v.push_back(make_pair(5, "FIV"));
				}
				if(s == "SIX"){
					v.push_back(make_pair(6, "SIX"));
				}
				if(s == "SVN"){
					v.push_back(make_pair(7, "SVN"));
				}
				if(s == "EGT"){
					v.push_back(make_pair(8, "EGT"));
				}
				if(s == "NIN"){
					v.push_back(make_pair(9, "NIN"));
				}
				
				
			}
			
			else temp += s[i];
			
			cout << temp << endl;
			
		}
		//정렬 
		sort(v.begin(), v.end());
		
		//OUTPUT
		for(int j=0; j<M; j++) {
			cout << v[j].second << " ";
		}
		
	}
	
	cin >> T;
	
	return 0;
}
