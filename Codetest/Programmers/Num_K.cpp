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
		//commands�� ����� �� ����� ���� 
		i = commands[t][0];
		j = commands[t][1];
		k = commands[t][2];
        
        //temp �迭�� ���ο� i���� j������ �迭�� ���� ���� 
		for(int p=i-1; p<j; p++) {
			int x = array[p];
			cout << x << " ";
			temp.push_back(x);
		}
		cout << endl;
		
		//temp �迭 ���� 
		sort(temp.begin(), temp.end());
		
		//temp�� k��° �ε��� ���� ��ȯ 
		answer.push_back(temp[k-1]);
		
		
		temp.clear();
	}	
	
	
	
	return answer;	
}
