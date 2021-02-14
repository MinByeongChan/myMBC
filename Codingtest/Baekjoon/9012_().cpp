#include <iostream>
#include <string>
#include <stack>

using namespace std;

//스택으로 괄호 검사 구현

//괄호검사 함수 
bool Check(string VPS){
	stack<char> st;
	
	for(int j=0; j<VPS.length(); j++){
			char x = VPS[j]; 
			if(x == ')') {
				//스택이 비어있는 상태에서 ')'가 들어온다는 뜻은
				// 먼저 '('가 오지 않았다는 뜻으로 바로 false 
				if(st.empty()){
					return false;
				}
				//스택에 '('가 있으면 pop시킴 
				if(x == ')' && st.top() == '(') {
					st.pop();
					continue;
				}
			}
			if(x == '(') st.push(x);
		}
	//스택이 비어있으면 검사가 모두 완료되었다는 뜻으로
	//true 반환 
	return st.empty();
}
int main(int argc, char** argv) {
	int T;//테스트 케이스
	
	string VPS = "";
	cin >> T;
	//각 테스트마다 string(괄호)을 받아 검사 
	for(int i=0; i<T; i++){
		cin >> VPS;
		
		if(Check(VPS)) 
			cout << "YES" << endl;
		else cout << "NO" << endl;
	} 

	return 0;
}
