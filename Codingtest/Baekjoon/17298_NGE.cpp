#include <iostream>
#include <stack>

#define MAX 1000000

using namespace std;

int A[MAX];
int N;
//stack<int> st;


//���� �����µ� ȿ�������� �ȵǴµ��ϴ�
//�� �õ��ص� �ȵǴ� ��������
//����� �����ϴ�

// sol1 ) ���þ��� Ǯ���� 
int NGE(int idx) {
	int i;
	//idx ������ �迭�� ���� ū ���� �߰ߵǸ� ��ȯ 
	for(i = idx+1; i<MAX; i++){
		if(A[i] == 0) break;
		if(A[i] > A[idx]) {
			return A[i];
		}
	}
	//ū���� ������ -1��ȯ 
	if(A[i] < A[idx]) return -1;
}

// sol 2) ���� �Ȱ��� ��������� ������ ����ؼ� �����غ� 
void NGE_stack(int idx) {
	int i;
	for(i=idx+1; i<MAX; i++) {
		if(A[i] == 0) break;
		if(A[i] > A[idx]){
			st.push(A[i]);
			break;
		}
	}
	if(A[i] < A[idx]) st.push(-1);
	if(!st.empty()) cout << st.top() << " ";
	st.pop();
}


int main(int argc, char** argv) {
	cin >> N;
	stack<int> st;
	
	for(int i=0; i<N; i++)
		cin >> A[i];
	
	for(int i=0; i<N; i++){
		//���۵Ǵ� �ε��� �迭�� ���ÿ� push 
		st.push(A[i]);
		
		//�ε��� ������ �迭�� ���� ��ĵ 
		for(int j=i+1; j<N; j++){
			//�ε����� �����ʰ��� �� ũ�� ��� 
			if(A[i] < A[j]){
				cout << A[j] << " ";
				break;
			}
			//ũ�� ������ �����ε��� push 
			else if(A[i] > A[j]){
				st.push(A[j]);
			}
		}
		
		//�ε��� �������� ��� �Ⱦ����� ū���� ���ٸ� -1 ��� 
 		if(st.top() == A[N-1]){
			cout << "-1 ";
		}
		//STACK CLEAR 
		while(!st.empty()){
			st.pop();
		}
	}

	return 0;
}


