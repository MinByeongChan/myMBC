#include <iostream>
 
using namespace std;
 
int main(int argc, char** argv) {
	int a=0; //고정비용
	int b=0; //가변비용
	int c=0; //제품 가격
	
	cin >> a >> b >> c;
	
	if(c-b <= 0) cout << -1 << endl;
	else cout << a / (c-b)+1 << endl;
	 
	return 0;
}
