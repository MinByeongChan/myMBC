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
		//�Է°��� 0�̸� ������ �Էµ� �� ���ֱ� 
		if(K == 0) st.pop();
		//K���� 0�� �ƴ� �ڿ����� push 
		else {
			st.push(K);
		}
	}
	//������ ������� 0��� 
	if(st.empty()){
		cout << 0 ;
		return 0;
	}
	//������� ������ ������ ��� ���� result�� ���� 
	while(!st.empty()){
		int x = st.top();
		st.pop();
		result += x;
	}
	//��� 
	cout << result;

	return 0;
}
