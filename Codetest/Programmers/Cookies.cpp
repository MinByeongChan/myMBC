#include <string>
#include <vector>
#include <iostream>

using namespace std;


// ȿ���� �׽�Ʈ �� ������ 3�� ����...
// ����Ž������ �����ؼ� �׷��� ����. 

//���� �迭, ������ �迭 �ΰ��� ������ ���� 
int solution(vector<int> cookie) {
	if(cookie.size() == 1 || cookie.size() > 2000) 
		return 0;
		
	int V_SIZE = cookie.size();
	int max = 0;
	
	int left_sum = 0, right_sum = 0;
	vector<int> l_arr(2000, 0);
	vector<int> r_arr(2000, 0);
	
	//����Ž������ ���� 
	//p: ���ʹ迭�� ���� �ε��� 
	for(int p=0; p<V_SIZE-1; p++) {
//		printf("------ p: %d ------\n", p);
		
		//l_arr �ʱ�ȭ 
		fill(l_arr.begin(), l_arr.end(), 0);
		left_sum = 0;
		
		//i: ���� �ε������� ���ʴ�� ���ذ��� ������ �ε����� �� 
		for(int i=p; i<V_SIZE-1; i++) {
//			printf("------ i: %d ------\n", i);
			 
			l_arr[i] = cookie[i];
			//���� �� 
			for(int s=i; s<V_SIZE; s++) {
				if(l_arr[s] == 0) break;
				else left_sum += l_arr[s];
			}
			
			//���� �ʱ�ȭ 
			fill(r_arr.begin(), r_arr.end(), 0);
			right_sum = 0;
			
			for(int j=i+1; j<V_SIZE; j++){
				r_arr[j] = cookie[j];
				right_sum += r_arr[j];
//				printf("left_sum: %d\n", left_sum);
//				printf("right_sum: %d\n", right_sum);
				//���������� �� ũ�� break 
				if(left_sum < right_sum) break;
				//�� ���� ������ �ִ밪 �� �� ���� 
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

