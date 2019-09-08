#include <iostream>
#include <stack>

#define MAX 1000000

using namespace std;

int A[MAX];
int N;
//stack<int> st;


//답은 나오는데 효율성땜에 안되는듯하다
//뭘 시도해도 안되는 문제였음
//기분이 상콤하다

// sol1 ) 스택없이 풀었음 
int NGE(int idx) {
	int i;
	//idx 오른쪽 배열의 값중 큰 값이 발견되면 반환 
	for(i = idx+1; i<MAX; i++){
		if(A[i] == 0) break;
		if(A[i] > A[idx]) {
			return A[i];
		}
	}
	//큰값이 없으면 -1반환 
	if(A[i] < A[idx]) return -1;
}

// sol 2) 위와 똑같은 방법이지만 스택을 사용해서 구현해봄 
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
		//시작되는 인덱스 배열을 스택에 push 
		st.push(A[i]);
		
		//인덱스 오른쪽 배열의 값을 스캔 
		for(int j=i+1; j<N; j++){
			//인덱스의 오른쪽값이 더 크면 출력 
			if(A[i] < A[j]){
				cout << A[j] << " ";
				break;
			}
			//크지 않으면 다음인덱스 push 
			else if(A[i] > A[j]){
				st.push(A[j]);
			}
		}
		
		//인덱스 오른쪽을 모두 훑었을때 큰값이 없다면 -1 출력 
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


