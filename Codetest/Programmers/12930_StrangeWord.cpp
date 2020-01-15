#include<iostream>
#include<string>
using namespace std;

//대문자 65~90
//소문자 97~122
string solution(string s) {
	s += ' '; // 마지막 인덱스까지 스캔하기 위해 ' '추가
	string answer = "";
	string tmp = "";
	int LEN = s.length(); // 입력 스트링 길이
	
	for (int i = 0; i < LEN; i++) {

		//공백이 보이기 전까지 tmp에 입력값 저장
		if(s[i] != ' ')
			tmp += s[i];
		//공백이 보이면 tmp를 처리
		else {
			int tmpSize = tmp.length(); // tmp 길이
			
			// 다시 tmp에 대한 반복문
			for (int j = 0; j < tmpSize; j++) {
				//짝수
				if (j % 2 == 0) 
					tmp[j] = toupper(tmp[j]); // 짝수면 무조건 대문자 
				//홀수
				else 
					tmp[j] = tolower(tmp[j]); // 홀수면 무조건 소문자
			}

			// answer에 tmp와 띄어쓰기를 추가
			answer += tmp;
			answer += ' ';
			tmp = "";
		}
		
	}
	
	//마지막 공백이 더해지므로 뒤에 인자는 제거
	answer.pop_back();
	
	return answer;
}

int main() {

    //INPUT
	string s = "try hello world";

    //OUTPUT
	cout << solution(s);

	return 0;
}