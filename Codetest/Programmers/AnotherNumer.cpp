#include <string>
#include <vector>

#define MAX 100001

using namespace std;

int arr[MAX];

//���� ��ȯ �Լ� 
int Binary(int x){
	int temp = x;
	int i=0;
	//1�� ���� ī��Ʈ 
	int cnt=0;
	while(1){
		if(temp == 0)
			break;
		arr[i] = (temp%2);
		temp/=2;
		//�迭�� 1�� �߰ߵǸ� 1�� ī��Ʈ  
		if(arr[i] == 1) cnt++;
		i++;
	}
	return cnt;
}

int solution(int n) {
    int answer = n;
    int Ncnt = Binary(n);
    while(1){
    	answer++;
    	//answer�� 1�� ������Ű�鼭 1�� ������ ������ �ٷ� ��� 
    	if(Binary(answer) == Ncnt){
			break;
		}
	}
    
    return answer;
}
