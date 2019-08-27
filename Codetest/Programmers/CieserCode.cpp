
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s = "a B z";
    int n = 4;
    string answer = "";
    string temp = "";
    
    //대소문자 구별하기 위한 string
    string small = "abcdefghijklnmopqrstuvwxyz";
    string large = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    
    //반복문으로 완전탐색을 통해 답을 구함
    for(int i=0; i<s.length(); i++){
    	int j=0;
        while(1){
	    //공백일때는 무시
            if(s[i] == ' '){
            	temp += ' ';
	    	break;
	    } 
	    //대문자인 경우
            if(s[i] == large[j]){
		//z인 경우 a로 변초기화후 다시 쉬프트
            	if(j+n > 25) j=-1;
                temp += large[j+n];
                break;
            }
	    //소문자인경우
	    //원리는 동일
            else if(s[i] == small[j]) {
            	if(j+n > 25) j=-1;
                temp += small[j+n];
                break;
            }
            j++;
        }
    }
    
    answer = temp;
    cout << answer << endl;
    return 0;
}
