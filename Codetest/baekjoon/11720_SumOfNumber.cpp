#include <iostream>
#include <cstdlib>

using namespace std;

//���ڸ� ���ڷ� ��ȯ���ִ� �Լ� 
int atoi_c(char c){
	int value = 0;
	if(c == '\0')
		return 0;
	//���� '0' ~ '9' ���� ���� c���� '0'�� ���� 
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
