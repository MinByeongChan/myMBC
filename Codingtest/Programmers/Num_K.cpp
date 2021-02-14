#include <iostream>
#include <vector>
#include <algorithm>

#define ARR_MAX 100

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
	vector<int> answer;
	int i, j, k;
    
	for(int t=0; t<commands.size(); t++) {
		vector<int> temp;
		//commands에 저장된 각 명령을 저장 
		i = commands[t][0];
		j = commands[t][1];
		k = commands[t][2];
        
        //temp 배열에 새로운 i부터 j까지의 배열을 새로 만듬 
		for(int p=i-1; p<j; p++) {
			int x = array[p];
			cout << x << " ";
			temp.push_back(x);
		}
		cout << endl;
		
		//temp 배열 정렬 
		sort(temp.begin(), temp.end());
		
		//temp의 k번째 인덱스 수를 반환 
		answer.push_back(temp[k-1]);
		
		
		temp.clear();
	}	
	
	
	
	return answer;	
}
