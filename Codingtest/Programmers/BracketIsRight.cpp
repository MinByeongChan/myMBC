#include<string>
#include <iostream>

#define MAX 100001

using namespace std;

//�ּ��� �����Ѵ� 
bool solution(string s)
{
    bool answer = true;

    char a[MAX];
	int state=0;
	for(int i=0; i<s.length(); i++) {
		if(state < 0) {
			answer = false;
			break;
		}
		if(s[i] == '('){
			state++;
		}
		else if(s[i] == ')'){
			state--;
		}
	}
    
	if(state == 0) return answer;
	else return answer = false;
}
