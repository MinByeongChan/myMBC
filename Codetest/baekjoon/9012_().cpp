#include <iostream>
#include <string>
#include <stack>

using namespace std;

//�������� ��ȣ �˻� ����

//��ȣ�˻� �Լ� 
bool Check(string VPS){
	stack<char> st;
	
	for(int j=0; j<VPS.length(); j++){
			char x = VPS[j]; 
			if(x == ')') {
				//������ ����ִ� ���¿��� ')'�� ���´ٴ� ����
				// ���� '('�� ���� �ʾҴٴ� ������ �ٷ� false 
				if(st.empty()){
					return false;
				}
				//���ÿ� '('�� ������ pop��Ŵ 
				if(x == ')' && st.top() == '(') {
					st.pop();
					continue;
				}
			}
			if(x == '(') st.push(x);
		}
	//������ ��������� �˻簡 ��� �Ϸ�Ǿ��ٴ� ������
	//true ��ȯ 
	return st.empty();
}
int main(int argc, char** argv) {
	int T;//�׽�Ʈ ���̽�
	
	string VPS = "";
	cin >> T;
	//�� �׽�Ʈ���� string(��ȣ)�� �޾� �˻� 
	for(int i=0; i<T; i++){
		cin >> VPS;
		
		if(Check(VPS)) 
			cout << "YES" << endl;
		else cout << "NO" << endl;
	} 

	return 0;
}
