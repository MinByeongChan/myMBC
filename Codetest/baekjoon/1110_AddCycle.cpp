#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0, n1 = 0, n2 = 0, sum = 0, result = 0, cycle = 0;

	cin >> n;
	
	//n이 한자리수 일 때 조건
	if (n < 10) 
		n *= 10;

	result = n;
	while (1) {
		n1 = result / 10;
		n2 = result % 10;
		sum = n1 + n2;
		//cout << "n1: "<< n1 << " n2: " << n2 <<" sum: " << sum << "\n";

		//cycle증가
		cycle++;

		n1 = n2 * 10;
		if (sum < 10) 
			n2 = sum;
		else 
			n2 = sum % 10;
		
		
		result = n1 + n2;
		//cout << "result: " << result << "\n";
		if (result == n) break;
	}

	cout << cycle;

	cin >> n;

	return 0;
}