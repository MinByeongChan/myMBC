#include <vector>
#include <iostream>
#include <cmath>

#define MAX 3001

using namespace std;

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(4);
    
    int cnt=0;
	int n_SIZE = nums.size();
	int arr[MAX] = {0,};
	
	//에라토스테네스의 체 
	//배수가 존재하는 것은 소수가 될 수 없다는 근거로 구현
	//초기 0과1은 소수가 아니므로 1로 초기화 
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2; i<sqrt((double)MAX); i++){
		if(arr[i] == 1) continue;
		for(int j=i*2; j<MAX; j+=i){
			arr[j] = 1;
		}
	}

	//완전탐색... 이거몰라서 해맴
    for(int i=0; i<n_SIZE; i++){
    	for(int j=i+1; j<n_SIZE; j++) {
			for(int k=j+1; k<n_SIZE; k++){
				int result = nums[i] + nums[j] + nums[k];
				if(arr[result] == 0){
					cnt++;
				}
			}
		}
	}	
    	
    cout << cnt ;
    
    return 0;
}


