#include <iostream>
#include <string>

using namespace std;


//���� �������� �ذ�  
//void Search(int left, int right) {
//	//Ż���� �� �� �ʿ��� ����!!! �������
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
		
		//�ʱⰪ���� ù�ε����� ������ �ε����� �Ű������� ����  
//		Search(0, end-1);


		// ����Ž������ �ذ�
		//p : ù �ε��� / q : ������ �ε��� 
		int p = 0;
		int q = end-1;
		int search_len = search.length();
		
		//ó������ ������ ��ĵ 
		while(p!=q) {
			string temp = "";
			
			// p+search_len���� �ؾ��ϴ°� ������ ������...
			// �Ź� �õ��� �� ���� temp�� Ž���� ���ڸ� temp�� �Է� 
			for(int i=p; i<p+search_len; i++) {
				temp += st[i];
//				cout << i << " / " << st[i] << " ";
			}
//			cout << temp << endl;;
			//temp�� Ž���� ���ڿ� ������ cnt���� 
			if(temp == search) cnt++;
			//�ݺ��� p 
			p++;
		}
		
		//OUTPUT
		cout << "#" << T << " " << cnt << endl;
	}

	return 0;
}
