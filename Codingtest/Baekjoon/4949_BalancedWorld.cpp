#include <iostream>
#include <string>
#include <stack>

using namespace std;

char temp;
stack<char> st;
	
//��ȣ �Ǵ��ϴ� �Լ� 
bool Decision(string s) {
	int len = s.length();
	
	//���ÿ� �����ִ� ������ ��� ���� 
	while(!st.empty()) {
		st.pop();
	}
			
	for(int i=0; i<len; i++){
		if(s[i] == ')' || s[i] == ']' ){
			//���ÿ� (�� ���»��¿��� )�� ������ false 
			if(st.empty()) {
				return false;
			}
			//���ÿ� (�� ����ְ� )�� ������ pop ��������! 
			if(st.top() == '('&& s[i] == ')' ){
				st.pop();
				continue;
			}
			if(st.top() == '['&& s[i] == ']' ){
				st.pop();
				continue;
			}
		}
		
		// '(' �̳� '['�� ������ ���ÿ� push 
		if(s[i] == '[' || s[i] == '(') {
			st.push(s[i]);
		}
	}
	
	//������ ��������� ������ �����ٴ� ������ true
	//���������� false 
	return st.empty();
}
int main(int argc, char** argv) {
	
	while(1){
		string s = "";
		//getline�Լ��� string�� ������� �޾ƿ��� �Լ�
		//�����ҵ��ϴ� �˾Ƶ��� 
		getline(cin, s);
		int len = s.length();
		if(s[0] == '.') break;
		//�Է°��� ������ ���� .�� �ƴϸ� no��� 
		if(s[len-1] != '.') {
			cout << "no" << endl;
			continue;
		}
		
		bool result = Decision(s);
		
		//��� 
		if(result) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
