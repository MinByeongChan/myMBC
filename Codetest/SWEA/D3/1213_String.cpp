#include <iostream>
#include <string>

using namespace std;


//분할 정복으로 해결  
//void Search(int left, int right) {
//	//탈출할 때 꼭 필요한 조건!!! 기억하자
//	if(right <= left) return ;
//	
//	int mid = (left + right) / 2;
//	int search_len = search.length();
//	
//	printf("(%d, %d)\n", left, right);
//	
//	Search(left, mid);
//	Search(mid+1, right);
//
//	int p = left, q = right;
//	
//	while(p!=q) {
//		temp = new char[search_len];
//		fill(temp, temp+search_len, ' ');
//		for(int i=p; i<search_len; i++) {
//			temp += st[i];
//		}
//		cout << "temp : " << temp <<  endl;
//		if(temp == search) cnt++;
//		p++;
//	}
//	
//}


int main(int argc, char** argv) {
	for(int t=1; t<=10; t++) {
		int T;
		int cnt = 0;
		string st;
		string search;
		cin >> T;
		
		cin >> search;
		cin >> st;
		
		int end = st.length();
		
		//초기값으로 첫인덱스와 마지막 인덱스를 매개변수로 전달  
//		Search(0, end-1);


		// 완전탐색으로 해결
		//p : 첫 인덱스 / q : 마지막 인덱스 
		int p = 0;
		int q = end-1;
		int search_len = search.length();
		
		//처음부터 끝까지 스캔 
		while(p!=q) {
			string temp = "";
			
			// p+search_len으로 해야하는걸 못보고 삽질함...
			// 매번 시도할 때 마다 temp에 탐색할 문자를 temp에 입력 
			for(int i=p; i<p+search_len; i++) {
				temp += st[i];
//				cout << i << " / " << st[i] << " ";
			}
//			cout << temp << endl;;
			//temp와 탐색할 문자와 같으면 cnt증가 
			if(temp == search) cnt++;
			//반복자 p 
			p++;
		}
		
		//OUTPUT
		cout << "#" << T << " " << cnt << endl;
	}

	return 0;
}
