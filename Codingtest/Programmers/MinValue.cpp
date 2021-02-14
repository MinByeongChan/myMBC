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
    
    //�� ��Ұ� ��� �迭�� �������� ���� 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    //A�� �Ǿտ�ҿ� B�� �� �ڿ�Һ��� �����ؼ�
	//���� ����� result�� ���� 
    int front=0, back=SIZE;
    for(int i=0; i<SIZE; i++){
    	result += A[i] * B[back - i - 1];
	}
    //OUTPUT
    cout << result << endl;

    return 0;
}
