#include <string>
#include <vector>

#define MAX 100001

using namespace std;

int arr[MAX];

//이진 변환 함수 
int Binary(int x){
	int temp = x;
	int i=0;
	//1의 개수 카운트 
	int cnt=0;
	while(1){
		if(temp == 0)
			break;
		arr[i] = (temp%2);
		temp/=2;
		//배열에 1이 발견되면 1을 카운트  
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
    	//answer를 1씩 증가시키면서 1의 개수가 같으면 바로 출력 
    	if(Binary(answer) == Ncnt){
			break;
		}
	}
    
    return answer;
}
