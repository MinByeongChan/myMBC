#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    set<string> s;
    set<string>::iterator iter;
    
    //clothes INSERT to set
    for(int i=0; i<clothes.size(); i++) {
    	for(int j=0; j<clothes[i].size(); j++){
    		cout << clothes[i][j] << endl;
    		if(iter != s.find(clothes[i][j])){
    			s.insert(clothes[i][j]);
			}
		}
	}
	
	for(iter = s.begin(); iter!=s.end(); iter++) {
		cout << 
	}


	
	
	
	
    return answer;
}

int main(int argc, char** argv) {
	vector<vector<string>> clothes{{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
	
	solution(clothes);
	
	cin >> clothes[0][0];
	
	return 0;
}
