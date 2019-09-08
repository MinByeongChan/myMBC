#include <iostream>
#include <string>
#include <stack>

using namespace std;

char temp;
stack<char> st;
	
//괄호 판단하는 함수 
bool Decision(string s) {
	int len = s.length();
	
	//스택에 남아있는 데이터 모두 제거 
	while(!st.empty()) {
		st.pop();
	}
			
	for(int i=0; i<len; i++){
		if(s[i] == ')' || s[i] == ']' ){
			//스택에 (가 없는상태에서 )가 들어오면 false 
			if(st.empty()) {
				return false;
			}
			//스택에 (가 들어있고 )가 들어오면 pop 균형잡힘! 
			if(st.top() == '('&& s[i] == ')' ){
				st.pop();
				continue;
			}
			if(st.top() == '['&& s[i] == ']' ){
				st.pop();
				continue;
			}
		}
		
		// '(' 이나 '['가 들어오면 스택에 push 
		if(s[i] == '[' || s[i] == '(') {
			st.push(s[i]);
		}
	}
	
	//스택이 비어있으면 균형이 잡혔다는 뜻으로 true
	//남아있으면 false 
	return st.empty();
}
int main(int argc, char** argv) {
	
	while(1){
		string s = "";
		//getline함수는 string의 공백까지 받아오는 함수
		//유용할듯하니 알아두자 
		getline(cin, s);
		int len = s.length();
		if(s[0] == '.') break;
		//입력값의 마지막 값이 .이 아니면 no출력 
		if(s[len-1] != '.') {
			cout << "no" << endl;
			continue;
		}
		
		bool result = Decision(s);
		
		//출력 
		if(result) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
