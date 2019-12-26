#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, K; // 물품의 수, 최대 버틸수 있는 무게



int main() {
	cin >> N >> K;

	//배열 초기화
	vector<pair<int, int> > v(N, make_pair(0,0));
	pair<int, int> tmp;

	//INPUT
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}



	/*for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}*/
	
	int mx = v[0].second;

	for (int i = 0; i < N; i++) {
		if (v[i].first > K)
			continue;

		tmp.first = v[i].first; // weight
		tmp.second = v[i].second; // value

		for (int j = i+1; j < N; j++) {
			int weight_sum = tmp.first + v[j].first;
			int value_sum = tmp.second + v[j].second;

			if (weight_sum > K)
				continue;
			
			tmp.first = weight_sum;
			tmp.second = value_sum;

			if (tmp.second > mx)
				mx = tmp.second;
		}
	}

	cout << mx;

	//cin >> N;

	return 0;
}