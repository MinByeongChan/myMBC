#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int main(){
	vector<int> answer;
	int commands[3][3] = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
	int array[MAX] = {1, 5, 2, 6, 3, 7, 4};
    int temp[MAX];
    int i, j, k;
    
    for(int p=0; p<3; p++){
    	cout << "COMMAND " << p+1 << endl;
    	temp[MAX];
        i = commands[p][0];
        j = commands[p][1];
        k = commands[p][2];
        if(i == j) {
        	answer.push_back(array[i-1]);
        	continue;
		}
        for(int q=i; q<=j; q++){
        	temp[q] = array[q-1];
        	cout << temp[q] << " ";
		}
		cout << endl;
        sort(temp+i, temp+j);
        answer.push_back(temp[k]);
    }
    
    for(int i=0; i<answer.size(); i++)
	    cout << answer[i] << " ";
    return 0;
}
