#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sugar;

void findSugar(int N){
	int n3=0, n5=0;
	
	while(1){
		int temp = N; // temp 초기화 
		
		if((n5 * 5) > temp) {
			if(sugar.size() == 0) sugar.push_back(-1);
			break;
		}
		if(n5!=0) temp = temp - (n5 * 5);
		
		while(1){
			if(temp <= 0) break;
			temp -= 3;
			n3++;
		}
		
		if(temp == 0) sugar.push_back(n5+n3);
		
		n5++;
		n3 = 0; 
	}
	
}

int main(int argc, char** argv) {
	int N=0; // 설탕 킬로그램
	scanf("%d", &N);
	
	findSugar(N);
	sort(sugar.begin(), sugar.end());
	cout << sugar[0] << ' ' << endl;
	
	return 0;
}
