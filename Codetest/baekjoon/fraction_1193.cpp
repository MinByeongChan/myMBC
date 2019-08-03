#include <iostream>
#include <vector>
#include <utility>
#define N 1001

using namespace std;


vector<pair<int, int> > v; //각 벡터 인덱스별로 순서에 맞는 좌표를 삽입

int index=1; //반복문의 횟수
int x=1;
int y=1;

//SWAP FUNCTION
void swap(int a, int b){
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

int main(int argc, char** argv) {
	int n=0;	
	int count=1; //벡터의 인덱스
	
	cin >> n; // 찾고 싶은 항의 인덱스 
	
	//1,2 번째 출력은 초기값으로 설정
	v.push_back(pair<int,int>(1, 1));
	v.push_back(pair<int,int>(1, 2));
	
	
	if(n <= 2){
		if(n == 1) 
			cout << v[0].first << "/" << v[0].second << endl;
		else
			cout << v[1].first << "/" << v[1].second << endl;
	}
	
	else{
		y++;
		//항의 인덱스는 지그재그 순으로 배열
		while(count < n){
			index++;
			if(x==1){
				for(int i=0; i < index; i++){
					count++;
					x++;
					if(y != 1) y--;
					v.push_back(pair<int,int>(x, y));
					cout << count << " : " << x << "/" << y << endl;
					if(count == n) {
						cout << count << endl;
						cout << v[count-1].first << "/" << v[count-1].second << endl;
						break;
					}
				}
				swap(x, y);
			}
			
			index++;
			if(y==1){
				for(int i=0; i < index; i++){
					count++;
					if(x != 1)x--;
					y++;
					v.push_back(pair<int,int>(x, y));
					cout << count << " : " << x << "/" << y << endl;
					if(count == n) {
						cout << count << endl;
						cout << v[count-1].first << "/" << v[count-1].second << endl;
						break;
					}
				}
				swap(x, y);
			}  			
		}
	}
	
	return 0;
}
