#include<iostream> 
#include<vector> // 벡터!!!!! 
#include<algorithm> // sort함수를 가져옴 
#include<utility> // pair를 가져옴 


using namespace std; // c++에서 사용해야함 잊지 말자! 

vector<pair<int, int>> v; // 벡터 안에 페어 생성 

//정렬하기 위한 비교함수 생성
//x가 같으면 y를 오름차순 정렬 
bool COMPARE(pair<int, int> a,pair<int, int> b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main(){
	int n;
	int x, y;
	scanf("%d", &n); // 점의 개수	
		
	//입력 
	for(int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		v.push_back(pair<int, int>(x, y));
	}
	
	sort(v.begin(), v.end(),COMPARE);
	
	//출력 
	for(int i=0; i<n; i++){
		cout << v[i].first << ' ' << v[i].second << endl;
	}
	
	return 0;
}
