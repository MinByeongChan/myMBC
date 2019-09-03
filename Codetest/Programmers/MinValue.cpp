#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000
 
using namespace std;

int main()
{
    int result=0;
    vector<int> A{1, 4, 2};
	vector<int> B{5, 4, 4};
	
    int SIZE = A.size();
    
    //각 요소가 담긴 배열을 오름차순 정렬 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    //A의 맨앞요소와 B의 맨 뒤요소부터 시작해서
	//곱한 결과를 result에 저장 
    int front=0, back=SIZE;
    for(int i=0; i<SIZE; i++){
    	result += A[i] * B[back - i - 1];
	}
    //OUTPUT
    cout << result << endl;

    return 0;
}
