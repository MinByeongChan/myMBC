#include <iostream>
#include <string>
#include <vector>

using namespace std;

//arr에 저장되어있는 인자가 나누어 떨어지는지 확인 
int Check(int lcm, vector<int> arr) {
	bool hi = true;
	
	for(int i=0; i<arr.size(); i++){
		//나누어 떨어지지 않으면 return false  
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
    //arr배열의 크기 
    int ARR_SIZE = arr.size();
    
    //arr중 최대값을 구해 LCM 시작 변수로 초기화 
    for(int i=0; i<ARR_SIZE; i++) {
    	if(LCM < arr[i]) LCM = arr[i];
	}
	
	//반복 
    while(1) {
    	//Check함수에서 true를 반환하면 반복문 종료 
    	if(Check(LCM, arr) == true) {
    		result = LCM;
    		return result;
		}
		//LCM을 1씩 증가시키면서 반복 
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
