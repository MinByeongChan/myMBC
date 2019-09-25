#include <iostream>
#include <string>

using namespace std;

//테스트 몇개에서 계속 실패 ... 왜그런지 모르겠음 
int Check(int left, int right, string s) {
	//left, right 범위 설정 
	if(right - left == 1) return 0;
	if(left == right) return 0;
	int mid = (left + right) / 2; //재귀함수 마다의 중앙값 
	
	int result = max(Check(left, mid, s), Check(mid+1, right, s));
	
	int p = mid-1; // mid 기준 왼쪽 
	int q = mid+1; // mid 기준 오른쪽 
	int cnt = 1;
	
	cout << "SUCCESS" << endl;
	
	while(p >= left && q <= right) {
		if(s[p] != s[q]) break;
		printf("(%d, %d)\n", p, q);
		q++;
		p--;
		cnt+=2;
	}
	cout << "cnt : " << cnt << endl;
	
	if(result < cnt) result = cnt;
	
	return result;
}


int solution(string s) {
	int max = 0;
	int right = s.length();
	if(right == 1) return max = 1;
	max = Check(0, right-1, s);
	
//정답은 잘 나오지만 효율성이 딸린다 함.	
//	for(int i=1; i<len; i++){
//		int pivot = i;
//		int left = pivot - 1;
//		int right = pivot + 1;
//		int cnt=1;
//		while(left >= 0 && right < len){
//			if(s[left] != s[right]) break;
// 			right++;
// 			left--;
// 			cnt+=2;
//		}
//		cout << cnt << endl;
//		if(max < cnt) max = cnt;
//		cnt = 0;
//	}   


    return max;
}

int main(){
	string ss = "abacde";
	
	cout <<"=> answer : " << solution(ss);
	
	cin >> ss;
	return 0;
}
