#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;


//�� �Լ�
bool cmp(pair<int, int> u, pair<int, int> v) {
	if (u.first != v.first)
		return u.first < v.first;
	// �ֺ��� ���� �����Ͱ� �������� ��
	// �Է� �����͸� ������������ ����
	else
		return u.second > v.second;
}

class Statistics {
private:
	int n, SIZE;

	//�Է� ������ ����
	vector<int> v;
	//�ֺ� ��� ����
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
	//���ġ
	int Avg() {
		double sum = 0;
		for (int i = 0; i < SIZE; i++) {
			sum += v[i];
		}
		
		return round(sum / n);
	}
	//�߰� ��
	int Mid() {
		return v[ n / 2 ];
	}

	
	int Fre() {
		if (SIZE == 1) return v[0];
		
		//�󵵼� �ִ밪
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
			// Ž����� �ߺ��Ǵ� ���� ���� ���
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

	//���� ���
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