#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp(){
	
}

int main(int argc, char** argv) {
	int T;
	float t_score[100] = {0, };
	vector<pair<float, int> > v;
	cin >> T;
	
	for(int t=1; t<=T; t++) {
		int N, K;
		cin >> N >> K; // N : �л��� �� , K : �л� �ε���
		string result = "";
		
		for(int i=0; i<N; i++){
			float mid, end, report; // �߰�, �⸻, ��������
			float s;
			cin >> mid >> end >> report;
			s += (mid * 0.35);
			s += (end * 0.45);
			s += (report * 0.20);
			
			v.push_back(make_pair(s, i));
			
			cout << v[i].first << ", " << v[i].second  << endl;
		} 
		
		cout << endl;
		//���� 
		sort(t_score, t_score+N);
		
		//���ĵ� �� ��� 
		for(int j=0; j<N; j++){
			cout << j << " : "<< t_score[j] << endl;
		}
		cout << endl;
		
	}
	
	cin >> T;

	return 0;
}
