#include <iostream>
#include <vector>
#define INF 100000
using namespace std;

int N;
long long int S;
int mn = INF;
vector<int> v;

int main() {
	cin >> N >> S;
	v.resize(N+1);
	//INPUT
	for (int i = 0; i < N; i++)
		cin >> v[i];

	//init variables
	int left = 0;
	int right = 0;
	//first index of sum is first value of vectors
	long long sum = v[0];

	//Use Two point Algorithm
	while (left <= right && right < N) {
		if (sum < S) {
			sum += v[++right];
		}
		else {
			int len = (right - left) + 1;
			if (len < mn)
				mn = len;
			sum -= v[left++];
			len--;
		}
		
	}

	// if total sum of vectors is lower than S
	// print "0"
	if (mn == INF)
		cout << "0";
	else 
		cout << mn;

	return 0;
}