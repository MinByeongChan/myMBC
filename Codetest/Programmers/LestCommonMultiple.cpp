#include <iostream>
#include <string>
#include <vector>

using namespace std;

//arr�� ����Ǿ��ִ� ���ڰ� ������ ���������� Ȯ�� 
int Check(int lcm, vector<int> arr) {
	bool hi = true;
	
	for(int i=0; i<arr.size(); i++){
		//������ �������� ������ return false  
    	if( (lcm % arr[i] ) != 0) {
    		hi = false;
    		break;
		}
	}
	
	return hi;
}

int solution(vector<int> arr) {
    int result = 0;
    int LCM = 2;
    //arr�迭�� ũ�� 
    int ARR_SIZE = arr.size();
    
    //arr�� �ִ밪�� ���� LCM ���� ������ �ʱ�ȭ 
    for(int i=0; i<ARR_SIZE; i++) {
    	if(LCM < arr[i]) LCM = arr[i];
	}
	
	//�ݺ� 
    while(1) {
    	//Check�Լ����� true�� ��ȯ�ϸ� �ݺ��� ���� 
    	if(Check(LCM, arr) == true) {
    		result = LCM;
    		return result;
		}
		//LCM�� 1�� ������Ű�鼭 �ݺ� 
    	LCM++;
	}
}

int main(int argc, char** argv) {
//	vector<int> arr = {2, 6, 8, 14};
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << solution(arr) << endl;;

	cin >> arr[0];
	
	return 0;
}
