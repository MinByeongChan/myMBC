#include<iostream>
#include <string>
using namespace std;

string A, B;
string tempA, tempB;

int main() {
	cin >> A >> B;

	for (int i = 2; i >= 0; i--) {
		tempA += A[i];
		tempB += B[i];
	}

	stoi(tempA) > stoi(tempB) ?
		cout << tempA :
		cout << tempB;

	cin >> A;


	return 0;
}