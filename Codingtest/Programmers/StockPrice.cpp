#include <iostream>
#include <string>
#include <vector>
using namespace std;

int SIZE;

vector<int> solution(vector<int> p) {
    SIZE = p.size();
	vector<int> answer(SIZE);
	
	for(int i=0; i<SIZE; i++) {
		for(int j=i+1; j<SIZE; j++) {
			if(p[i] <= p[j]){
				answer[i]++;
			}
			else {
				answer[i]++;
				break;
			}
		}
	}
	
    return answer;
}

int main(int argc, char** argv) {
	vector<int> p{1, 2, 3, 2, 3};
	vector<int> a(solution(p));
	
	for(int i=0; i<a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cin >> p[0];
	
	return 0;
}
