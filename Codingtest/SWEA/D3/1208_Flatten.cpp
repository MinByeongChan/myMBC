#include <iostream>
#include <vector>

#define ROWMAX 100
#define HIGHMAX 100

using namespace std;


int main(int argc, char** argv) {
	int T=0;
	while(T != 10) {
		int dump; // 상자를 옮기는 횟수 
		cin >> dump;
		
//		int arr[ROWMAX];
		vector<pair<int, int > > arr;
		
		for(int i=0; i<ROWMAX; i++) {
			int a;
			cin >> a;
			arr.push_back(make_pair(a, i));
		}
		
		for(int i=0; i<ROWMAX; i++) {
			cout << arr[i].first << " " << arr[i].second << endl;
		}
		
		while(dump != 0) {
			dump--;
			cout << "dump : " << dump << endl;
			
			vector<pair<int, int > > max;
			vector<pair<int, int > > min;
			
			max.push_back(make_pair(0, 0));
			min.push_back(make_pair(HIGHMAX, 0));
			
			
			// i: 최대일 때 인덱스
			// j: 최소일 때 인덱스 
			int i, j;
			//완전탐색으로 최대값 탐색              
			for(i=0; i<ROWMAX; i++) {
				if(arr[i].first < min[0].first) {
					max[0].first = arr[i].first;
					max[0].second = arr[i].second;
				}
			}
			//완전탐색으로 최소값 탐색
			for(j=0; j<ROWMAX; j++) {
				if(arr[j].first < min[0].first) {
					min[0].first = arr[j].fisrt;
					min[0].second = arr[j].second;
				}
			}
			
			
		}
		
		
		T++;
		cout <<"#"<< T <<" "<<  endl;
			
	}
	cin >> T;


	return 0;
}
