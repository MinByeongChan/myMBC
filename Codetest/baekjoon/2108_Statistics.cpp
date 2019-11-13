#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;


//비교 함수
bool cmp(pair<int, int> u, pair<int, int> v) {
	if (u.first != v.first)
		return u.first < v.first;
	// 최빈값이 같은 데이터가 여러개일 때
	// 입력 데이터를 오름차순으로 정렬
	else
		return u.second > v.second;
}

class Statistics {
private:
	int n, SIZE;

	//입력 데이터 벡터
	vector<int> v;
	//최빈값 페어 벡터
	vector<pair<int, int>> fre;
	

public:
	Statistics() :n(1) {
		v.resize(1);
	}

	Statistics(int n1) :n(n1) {
		v.resize(n1);
	}

	//INPUT 
	void set() {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		SIZE = v.size();

	}
	//평균치
	int Avg() {
		double sum = 0;
		for (int i = 0; i < SIZE; i++) {
			sum += v[i];
		}
		
		return round(sum / n);
	}
	//중간 값
	int Mid() {
		return v[ n / 2 ];
	}

	
	int Fre() {
		if (SIZE == 1) return v[0];
		
		//빈도수 최대값
		int freMax = 500000;
		int freSize;
		for (int i = 0; i < n; i++) {
			int st = 0;
			freSize = fre.size();
			
			for (int j = 0; j < freSize; j++) {
				if (fre[j].second == v[i]) {
					fre[j].first++;
					st = 1;
				}
			}
			// 탐색결과 중복되는 값이 없을 경우
			if (st == 0) {
				fre.push_back(make_pair(1, v[i]));
			}
		}

		//RETURN
		sort(fre.begin(), fre.end(), cmp);

		freSize = fre.size();
		if (fre[freSize - 1].first == fre[freSize - 2].first)
			return fre[freSize - 2].second;		
		else 
			return fre[freSize - 1].second;
	}

	//범위 계산
	int Range() {
		if (SIZE == 1) return 0;
		else
			return (v[SIZE- 1] - v[0]);
	}

};

int main() {
	int N;
	cin >> N;

	Statistics s(N);

	//OUTPUT
	cout << s.Avg() << "\n";
	cout << s.Mid() << "\n";
	cout << s.Fre() << "\n";
	cout << s.Range() << "\n";

	cin >> N;
	return 0;
}