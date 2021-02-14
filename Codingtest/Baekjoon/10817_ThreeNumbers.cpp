#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int number[3];
	
	for (int i = 0; i < 3; i++)
		cin >> number[i];
	
	//sort
	sort(number, number + 3);

	for (int i = 0; i < 3; i++)
		cout << number[i] << " ";
	cout << "\n";

	cout << number[1];

	cin >> number[0];

	return 0;
}