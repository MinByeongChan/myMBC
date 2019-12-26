#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, K; // ��ǰ�� ��, �ִ� ��ƿ�� �ִ� ����
int mx = 0; //�ִ밪 ����

vector<pair<int, int> > v;
pair<int, int> tmp(0, 0);


int main() {
	cin >> N >> K;

	//�迭 �ʱ�ȭ
	v.resize(N, make_pair(0, 0));
	
	//INPUT
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;

	}


	/*
	for (int i = 0; i < N+1; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	*/

	for (int i = 0; i < N; i++) {
	
		if (v[i].first > K)
			continue;

		tmp.first = v[i].first; // weight
		tmp.second = v[i].second; // value

		if (tmp.second > mx)
			mx = tmp.second;

		for (int j = i + 1; j < N; j++) {
			int weight_sum = tmp.first + v[j].first;
			int value_sum = tmp.second + v[j].second;


			if (weight_sum > K )
				continue;

			tmp.first = weight_sum;
			tmp.second = value_sum;

			if (tmp.second > mx)
				mx = tmp.second;
		}
	}


	cout << mx;

	return 0;
}