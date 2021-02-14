#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";		
	int P_SIZE = participant.size();	
	
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	
	for(int i=0; i<completion.size(); i++) {
		if(completion[i] != participant[i]){
			return participant[i];
		}
	}
	return participant[P_SIZE-1];
	
	//unordered_map을 사용하여 푼 풀이 
//	string answer = "";
//    unordered_map<string, int> strMap;
//    for(auto elem : completion)
//    {
//        if(strMap.end() == strMap.find(elem))
//            strMap.insert(make_pair(elem, 1));
//        else
//            strMap[elem]++;
//    }
//
//    for(auto elem : participant)
//    {
//        if(strMap.end() == strMap.find(elem))
//        {
//            answer = elem;
//            break;
//        }
//        else
//        {
//            strMap[elem]--;
//            if(strMap[elem] < 0)
//            {
//                answer = elem;
//                break;
//            }
//        }
//    }
//    return answer;
//    
	//시간초과 문제에서 막힘 
//	for(int i=0; i<completion.size(); i++){
//		for(int j=0; j<participant.size(); j++) {
//			if(completion[i] == participant[j]) {
//				if(completion[i] != "" ) {
////					cout << completion[i] << endl;
//					participant[j] = "";
//					break;
//				}
//			} 
//		}
//	}
//	
//	for(int i=0; i<participant.size(); i++) {
//		if(participant[i] != "") {
//			answer += participant[i];
//		}
//	}
//    
//    return answer;
}

int main(int argc, char** argv) {
	vector<string> participant{"mislav", "stanko", "mislav", "ana"};
	vector<string> completion{"stanko", "ana", "mislav"};
	
	cout << "answer: " << solution(participant, completion) << endl;
	cin >> participant[0];

	return 0;
}
