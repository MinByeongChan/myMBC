#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

//int arr[MAX];
vector<pair<int, int> > arr[MAX];

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for(int t=1; t<=T; t++) {
		int N;
		cin >> N;
		
		int result=0;
		int max = 0;
		for(int i=0; i<N; i++){
			int a;
			cin >> a;
			arr[i] = make_pair(a, i+1);
		}
		
		for(int i=0; i<N; i++) {
			if(arr[i].first > max) max = arr[i].first;
		}
		
		for(int i=0; i<N; i++){
			cout << arr[i].first << " " << arr[i].second << endl;
		}
		
		//첫날에 가장 값이 높을 때 0 출력 
//		if(arr[0].first == max) result = 0;
//		else {
//			for(int i=0; i<N; i++) {
//				if(arr[0].first != max) {
//					
//				}
//			}
//		}
		
		
		
		printf("#%d %d\n", t, result);
	}

	cin >> T;

	return 0;
}
