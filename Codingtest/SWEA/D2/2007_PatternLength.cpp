#include <iostream>
#include <string>

#define S_MAX 31

using namespace std;

//C로 풀려다가 SWEA 컴파일러가 C제공안한다는걸 뒤늦게 암...
//이런것이 자고로 삽질이란 것이다
//그래도 string을 또한번 진득하게 다뤄봣던 문제 
int main(int argc, char** argv) {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
//		char str[S_MAX] = " ";
//		char temp[S_MAX] = " "; 	
		string str;
		string temp;
		
		//C++에서 string 쓸 때, printf, scanf는 정상적으로 동작x 
		
		//scanf("%d", &str);
		cin >> str;
		
		int str_SIZE = str.length();
		int success = 0;
		
		//입력 문자열의 최대 길이만큼 반복 
		for(int i=0; i<str_SIZE; i++){
			if(success == 1) break;
			//temp에 문자열 하나씩 더해가면서 str(입력 문자열)과 비교 
			temp += str[i];
			
//			printf("%d / temp : %s\n", i, &temp);
			
			cout << temp << endl;
			
			//C++ 버전 
			//temp 길이 
			int tmp_SIZE = temp.length();
			
			//temp 문자열에서 첫 문자를 다음 문자와 비교 
			for(int j=tmp_SIZE; j<str_SIZE; j+=tmp_SIZE){
				//substr() : 문자열 인덱스 x to y 까지만을 반환하는 함수
				//유용하니 알아두자 
				if(temp == str.substr(j, tmp_SIZE)) {
					//문자열이 같으면 success변수를 1로 변경하고 반복문 탈출 
					success = 1;
					continue;
				}
				else break;
			}
			
			// C 버전 
//			for(int j=tmp_SIZE; j<str_SIZE; j+=tmp_SIZE){
//				if(temp == str.substr(1, tmp_SIZE))
//				if(temp[0] == str[j]) {
//					success = 1;
//					break;
//				}
//				else break;
//			}
		}
		
		
		int result = temp.length();
		cout << "#"<<t<<" "<<result<<endl;
	}

	scanf("%d", &T);
	
	return 0;
}
