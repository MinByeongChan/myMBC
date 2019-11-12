#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
//#include <set>
using namespace std;


class Statistics {
private:
	int n, SIZE;

	vector<int> v;
	//set<pair<int, int>> fre;
	vector<pair<int, int>> fre;
	

public:
	Statistics() :n(1) {
		v.resize(1);
	}

	Statistics(int n1) :n(n1) {
		v.resize(n1);
		/*fre.resize(n1);
		fill(fre.begin(), fre.end(), 0);*/
	}

	void set() {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		SIZE = v.size();

	}

	int Avg() {
		double sum = 0;
		for (int i = 0; i < SIZE; i++) {
			sum += v[i];
		}
		
		return round(sum / n);
	}

	int Mid() {
		return v[ n / 2 ];
	}

	int Fre() {
		if (SIZE == 1) return v[0];
		
		fre.push_back(make_pair(v[0], 0));
		for (int i = 1; i < n; i++) {
			
		}


		for (int i = 0; i < n; i++) {
			cout << fre[i].first << "\n";
		}

	}

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

	s.set();
	cout << s.Avg() << "\n";
	cout << s.Mid() << "\n";
	cout << s.Fre() << "\n";
	cout << s.Range() << "\n";

	cin >> N;
	return 0;
}