#include <iostream>
#include <string>

using namespace std;

//�׽�Ʈ ����� ��� ���� ... �ֱ׷��� �𸣰��� 
int Check(int left, int right, string s) {
	//left, right ���� ���� 
	if(right - left == 1) return 0;
	if(left == right) return 0;
	int mid = (left + right) / 2; //����Լ� ������ �߾Ӱ� 
	
	int result = max(Check(left, mid, s), Check(mid+1, right, s));
	
	int p = mid-1; // mid ���� ���� 
	int q = mid+1; // mid ���� ������ 
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
	
//������ �� �������� ȿ������ ������ ��.	
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
