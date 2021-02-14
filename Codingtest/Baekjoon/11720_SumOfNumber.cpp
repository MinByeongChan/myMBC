#include <iostream>
#include <cstdlib>

using namespace std;

//문자를 숫자로 변환해주는 함수 
int atoi_c(char c){
	int value = 0;
	if(c == '\0')
		return 0;
	//문자 '0' ~ '9' 까지 오면 c에서 '0'을 빼줌 
	if(c >= '0' && c <= '9')
		value = c - '0';
		
	return value;
}

int main(int argc, char** argv) {
	int N;
	string number;
//	const char * number2 = number.c_str();
	cin >> N >> number;
	
	int sum = 0;
	
	for(int i=0; i<number.size(); i++) {
		sum += atoi_c(number[i]);
		
	}
	
	cout << sum;
	
	cin >> N;
	return 0;
}
