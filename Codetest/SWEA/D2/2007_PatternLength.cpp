#include <iostream>
#include <string>

#define S_MAX 31

using namespace std;

//C�� Ǯ���ٰ� SWEA �����Ϸ��� C�������Ѵٴ°� �ڴʰ� ��...
//�̷����� �ڰ�� �����̶� ���̴�
//�׷��� string�� ���ѹ� �����ϰ� �ٷ�f�� ���� 
int main(int argc, char** argv) {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
//		char str[S_MAX] = " ";
//		char temp[S_MAX] = " "; 	
		string str;
		string temp;
		
		//C++���� string �� ��, printf, scanf�� ���������� ����x 
		
		//scanf("%d", &str);
		cin >> str;
		
		int str_SIZE = str.length();
		int success = 0;
		
		//�Է� ���ڿ��� �ִ� ���̸�ŭ �ݺ� 
		for(int i=0; i<str_SIZE; i++){
			if(success == 1) break;
			//temp�� ���ڿ� �ϳ��� ���ذ��鼭 str(�Է� ���ڿ�)�� �� 
			temp += str[i];
			
//			printf("%d / temp : %s\n", i, &temp);
			
			cout << temp << endl;
			
			//C++ ���� 
			//temp ���� 
			int tmp_SIZE = temp.length();
			
			//temp ���ڿ����� ù ���ڸ� ���� ���ڿ� �� 
			for(int j=tmp_SIZE; j<str_SIZE; j+=tmp_SIZE){
				//substr() : ���ڿ� �ε��� x to y �������� ��ȯ�ϴ� �Լ�
				//�����ϴ� �˾Ƶ��� 
				if(temp == str.substr(j, tmp_SIZE)) {
					//���ڿ��� ������ success������ 1�� �����ϰ� �ݺ��� Ż�� 
					success = 1;
					continue;
				}
				else break;
			}
			
			// C ���� 
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
