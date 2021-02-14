#include <iostream>
#include <string>

#define MAX 10001

using namespace std;

//t는 top을 의미
//stack을 배열로 구현 
int stack[10001], t = -1;  

//push 함수
//top을 미리 증가시키고 stack에 data push 
void push(int x){
	stack[++t] = x;
}
//비어있으면 1 반환 그렇지 않으면 0 
int empty(){
	if(t < 0) return 1;
	else return 0;
}
//비어있을 떄 pop을 하면 -1출력
//스택에 data가 존재할때 top에 0을 넣고 top을 감소 
void pop(){
	if(empty() == 1)
		cout << "-1" << endl;
	else {
		cout << stack[t] << endl;
		stack[t--] = 0;
	}
}
//size출력
//초기 스택이 비어있을때 
//top은 -1을 가리키기 때문에 +1을 해줌 
void size(){
	cout << t+1 << endl;
}
//top함수 
void top(){
	if(empty() == 1) cout << -1 << endl;
	else cout << stack[t] << endl;
}

int main(int argc, char** argv) {
	int N; // 명령의 수 
	cin >> N;
	string s;
	
	//switch-case문으로 돌리면 되는데 뻘짓함
	//substr()함수를 사용해 문자를 받으면 동작하도록 구현 
	for(int i=0; i<N; i++){
		cin >> s;
		int len = s.length();
		 
		if(s.substr(0, 4) == "push") {
			int x;
			//push 데이터의 값을 다시한번 입력 받음 
			cin >> x;
			push(x);
		}
		if(s.substr(0, 3) == "top"){
			top();
		}
		if(s.substr(0, 4) == "size"){
			size();
		}
		if(s.substr(0, 5) == "empty"){
			cout << empty() << endl;
		}
		if(s.substr(0, 3) == "pop"){
			pop();
		}
	}
	
	return 0;
}
