#include <string>
#include <vector>
#include <iostream>

#define MAX 100001

using namespace std;

int main() {
	//�Է� 
	string s = "1 2 3 4";
	// ���ڿ��� Ž���ϴ� �������� �����÷ο찡 �߻��ϱ� ������
	s += " ";   
	string answer = "";
	//�ӽ� ���� ���� 
    string temp = "";
	//�ִ� �ּ� �� 
	int max = -MAX;
    int min = MAX;
    
    //�� ���̽� ���� start�� �ʱ�ȭ 
    int start=0, j=0;
    int cnt = 1;
    while(1){
    	printf("------- cnt : %d -------\n", cnt++);
    	//�ʱ�ȭ �� j���� �ٽ� Ž�� 
    	for(j=start; j<s.length(); j++){
    		if(s[j] == ' ') break;
		}
		 
		if(j == (s.length())) break;
		printf("%d %d : ", start, j);
		
		// �ε��� start���� j���� ����ϴ� substr()��� 
		temp = s.substr(start, j);		
		int a = stoi(temp); // ���ڸ� ���������� 
		cout << a << endl;
        if(a >= max) max = a;
		if(a <= min) min = a;    
        temp = "";
        //start�� j�� ������������ �ʱ�ȭ�Ͽ� �ٽ� Ž�� 
        start=j+1;
	}
	
    cout << endl;
    //������ ���� �ִ�,�ּҸ� �ٽ� ���ڷ� ���� 
    string x = to_string(max);
    string y = to_string(min);
    
    //answer�� ������������ ����ؾ� �ϱ� ������ �ٽ� �ʱ�ȭ 
    answer +=y;
    answer +=' ';
    answer +=x;
    
    cout << answer << endl;
    
    return 0;
}


