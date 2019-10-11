#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int LEN;

int Check(string a, int idx) {
	if(a[idx] == ')') return 0;
	
	stack<char> st;
	int cnt = 0;
	int i = idx;
	st.push('(');
	
	while(!st.empty()) {
		i++;
		char x = st.top();
		if(x == '(' && a[i] == '(') {
			st.push('(');
			cout << "( ";
		}
		
		else if(a[i-1] == '(' && a[i] == ')'){
			st.pop();
			if(st.size() != 0)
				cnt++;
		}
		else if(a[i] == ')'){
			st.pop();
		}
	}
	
	//시도가 한번 이루어질 경우 return 0 
	if(i - idx == 1) return cnt = 0;
	else return cnt+1;
}

int solution(string arrangement) {
    int answer = 0;
    LEN = arrangement.length();
    
    //각 인덱스마다 길이를 검사 
    for(int i=0; i<LEN-1; i++) {
    	answer += Check(arrangement, i);
	}    
    
    return answer;
}

int main(int argc, char** argv) {
	string arrangement = "()(((()())(())()))(())";
	
	cout << solution(arrangement) << endl;
	
	cin >> arrangement;

	return 0;
}
