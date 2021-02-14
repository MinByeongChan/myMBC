#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 효율성 테스트 중 마지막 3개 실패...
// 완전탐색으로 구현해서 그런거 같다. 

//왼쪽 배열, 오른쪽 배열 두개로 나누어 구현 
int solution(vector<int> cookie) {
	if(cookie.size() == 1 || cookie.size() > 2000) 
		return 0;
		
	int V_SIZE = cookie.size();
	int max = 0;
	
	int left_sum = 0, right_sum = 0;
	vector<int> l_arr(2000, 0);
	vector<int> r_arr(2000, 0);
	
	//완전탐색으로 구현 
	//p: 왼쪽배열의 시작 인덱스 
	for(int p=0; p<V_SIZE-1; p++) {
//		printf("------ p: %d ------\n", p);
		
		//l_arr 초기화 
		fill(l_arr.begin(), l_arr.end(), 0);
		left_sum = 0;
		
		//i: 시작 인덱스부터 차례대로 더해가며 오른쪽 인덱스와 비교 
		for(int i=p; i<V_SIZE-1; i++) {
//			printf("------ i: %d ------\n", i);
			 
			l_arr[i] = cookie[i];
			//왼쪽 합 
			for(int s=i; s<V_SIZE; s++) {
				if(l_arr[s] == 0) break;
				else left_sum += l_arr[s];
			}
			
			//변수 초기화 
			fill(r_arr.begin(), r_arr.end(), 0);
			right_sum = 0;
			
			for(int j=i+1; j<V_SIZE; j++){
				r_arr[j] = cookie[j];
				right_sum += r_arr[j];
//				printf("left_sum: %d\n", left_sum);
//				printf("right_sum: %d\n", right_sum);
				//오른쪽합이 더 크면 break 
				if(left_sum < right_sum) break;
				//양 합이 같으면 최대값 비교 후 갱신 
				if(left_sum == right_sum) {
					if(max < right_sum) max = right_sum;
//					printf("max: %d\n", max);
					break;
				}
				if(left_sum > right_sum) continue;
			}
			
		}
	}
	
	//return max
	return max;
}

int main(int argc, char** argv) {
	vector<int> cookie = { 1, 1, 2, 3 };
	cout << "result : " << solution(cookie);
	
	cin >> cookie[1];
	
	return 0;
}

