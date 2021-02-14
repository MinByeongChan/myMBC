#include <iostream>
#include <vector>

using namespace std;

//stack���� Ǯ���ٰ� �ð� ����Ƹ��� ����... 
vector<int> solution(vector<int> heights) {
	int HEIGHTS_SIZE = heights.size();
    vector<int> answer(HEIGHTS_SIZE, -1);
    
    //�� ���� for������ ����
    //������ �ʿ���� �����
	for(int i=HEIGHTS_SIZE-1; i>=0; i--) {
		for(int j=i-1; j>=0; j--) {
			if(heights[i] < heights[j]) {
				answer[i] = j+1;
				break;
			}
		}
		if(answer[i] == -1) answer[i] = 0;
	}
    
    return answer;
}

int main(int argc, char** argv) {
	vector<int> heights{1,5,3,6,7,6,5};
	vector<int> v(solution(heights));
	 
	cout << "answer: " << endl;
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	
	cin >> heights[0];
	 
	return 0;
}
