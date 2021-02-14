#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
	int N, K;
	stack<int> st;
	int result=0;
	
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> K;
		//입력값이 0이면 그전에 입력된 값 없애기 
		if(K == 0) st.pop();
		//K값이 0이 아닌 자연수면 push 
		else {
			st.push(K);
		}
	}
	//스택이 비었으면 0출력 
	if(st.empty()){
		cout << 0 ;
		return 0;
	}
	//비어있지 않으면 스택의 모든 값을 result에 더함 
	while(!st.empty()){
		int x = st.top();
		st.pop();
		result += x;
	}
	//출력 
	cout << result;

	return 0;
}
