#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char** argv) {
	vector< pair<int, int> > v; //x kg, y cm
	int n; // 사람 수 
	int x, y;
	
	cin >> n;

	int* rank = new int[n]; //등수에 대한 배열변수 선언
	
	//각 인덱스에 대한 등수 초기화 
	for(int i=0; i<n; i++) rank[i] = 1;
	
	//v에 대한 x, y입력 
	for(int i=0; i<n; i++){
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	//각 인덱스를 브루트포스방식으로 일일이 비교
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if((v[i].first < v[j].first) 
				&& (v[i].second < v[j].second) ){
					if(v[i] != v[j])rank[i]++;
			}
		}
	} 
	
	//출력
	for(int i=0; i<n; i++) cout << rank[i] << ' ';

	//동적 배열 해제
	delete[] rank;
	
	return 0;
}
