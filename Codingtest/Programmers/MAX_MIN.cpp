#include <string>
#include <vector>
#include <iostream>

#define MAX 100001

using namespace std;

int main() {
	//입력 
	string s = "1 2 3 4";
	// 문자열을 탐색하는 과정에서 오버플로우가 발생하기 때문에
	s += " ";   
	string answer = "";
	//임시 저장 변수 
    string temp = "";
	//최대 최소 값 
	int max = -MAX;
    int min = MAX;
    
    //각 케이스 마다 start를 초기화 
    int start=0, j=0;
    int cnt = 1;
    while(1){
    	printf("------- cnt : %d -------\n", cnt++);
    	//초기화 된 j부터 다시 탐색 
    	for(j=start; j<s.length(); j++){
    		if(s[j] == ' ') break;
		}
		 
		if(j == (s.length())) break;
		printf("%d %d : ", start, j);
		
		// 인덱스 start부터 j까지 출력하는 substr()사용 
		temp = s.substr(start, j);		
		int a = stoi(temp); // 문자를 정수형으로 
		cout << a << endl;
        if(a >= max) max = a;
		if(a <= min) min = a;    
        temp = "";
        //start를 j의 시작지점으로 초기화하여 다시 탐색 
        start=j+1;
	}
	
    cout << endl;
    //위에서 구한 최대,최소를 다시 문자로 변형 
    string x = to_string(max);
    string y = to_string(min);
    
    //answer를 문자형식으로 출력해야 하기 때문에 다시 초기화 
    answer +=y;
    answer +=' ';
    answer +=x;
    
    cout << answer << endl;
    
    return 0;
}


