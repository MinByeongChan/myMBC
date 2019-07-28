#include <iostream>

int main()
{
	int count[5];
	int array[30] = {
		3, 1, 2, 4, 5,  1, 3, 5, 4, 2,
		1, 2, 4, 3, 5, 1, 5, 4, 3, 2,
		5, 3, 5, 3, 1, 2, 4, 3, 2, 1
	};
	for (int i = 0; i < 5; i++)
		count[i] = 0;
	for (int i = 0; i < 30; i++) {
		count[array[i] - 1]++;
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)
				printf("%d", i+1);
		}
	}
	return 0;	
		
}
