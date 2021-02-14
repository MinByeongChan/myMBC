#include <iostream>
#include <string>
#include <vector>

#define MAX 101

using namespace std;


int main() {
	vector<int> answer;
	vector<int> progresses;
	vector<int> speeds;
	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);
	progresses.push_back(32);
	progresses.push_back(15);
	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);
	speeds.push_back(10);
	speeds.push_back(10);
	
	
	int result=0;
	int day = 1;
	int v_size = progresses.size();
	int dp = 0;
	int arr[MAX] = {0, };
	
	cout << v_size << endl;
	while(dp != v_size){
		cout << "DAY : " << day << " / dp : " << dp << endl;
		for(int i=0; i<v_size; i++){
			progresses[i] += speeds[i];
			cout << progresses[i] << " ";
		}
		cout << endl;
	
		for(int i=0; i<v_size; i++){
			if(progresses[i] >= 100 && arr[i] == 0) {
				arr[i] = -1;
				result++;
				printf("result : %d\n", result);
			}
		}		
		
		if( (result >= 1) && (progresses[0] >= 100) ){
			answer.push_back(result);
			dp+=result;
			result=0;
			cout << "send / " << answer.size() <<endl;
		}
		day++;
	}
	
	for(int i=0; i<answer.size(); i++){
		cout << answer[i] << " ";
	}
	
    return 0;
}


