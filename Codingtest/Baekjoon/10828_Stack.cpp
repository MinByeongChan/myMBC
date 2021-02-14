#include <iostream>
#include <string>

#define MAX 10001

using namespace std;

//t�� top�� �ǹ�
//stack�� �迭�� ���� 
int stack[10001], t = -1;  

//push �Լ�
//top�� �̸� ������Ű�� stack�� data push 
void push(int x){
	stack[++t] = x;
}
//��������� 1 ��ȯ �׷��� ������ 0 
int empty(){
	if(t < 0) return 1;
	else return 0;
}
//������� �� pop�� �ϸ� -1���
//���ÿ� data�� �����Ҷ� top�� 0�� �ְ� top�� ���� 
void pop(){
	if(empty() == 1)
		cout << "-1" << endl;
	else {
		cout << stack[t] << endl;
		stack[t--] = 0;
	}
}
//size���
//�ʱ� ������ ��������� 
//top�� -1�� ����Ű�� ������ +1�� ���� 
void size(){
	cout << t+1 << endl;
}
//top�Լ� 
void top(){
	if(empty() == 1) cout << -1 << endl;
	else cout << stack[t] << endl;
}

int main(int argc, char** argv) {
	int N; // ����� �� 
	cin >> N;
	string s;
	
	//switch-case������ ������ �Ǵµ� ������
	//substr()�Լ��� ����� ���ڸ� ������ �����ϵ��� ���� 
	for(int i=0; i<N; i++){
		cin >> s;
		int len = s.length();
		 
		if(s.substr(0, 4) == "push") {
			int x;
			//push �������� ���� �ٽ��ѹ� �Է� ���� 
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
