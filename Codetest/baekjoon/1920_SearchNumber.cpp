#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arrA[100000] = {0, };
int arrB[100000] = {0, };

int compare(const void *a, const void *b) {
	return ( *(int *)a - *(int *)b);
}

//탑다운 방식 
int BinarySearch(int left, int right, int x) {
	int mid = (left+right) / 2;
	//mid와 같으면 ck 를 true로 하여 출력
	if(left > right) 
		return 0;
	if(arrA[mid] == x)
		return 1;
	else if(arrA[mid] < x) 
		BinarySearch(mid+1, right, x);
	else if(arrA[mid] > x)
		BinarySearch(left, mid-1, x);
}

int main(int argc, char** argv) {
	cin >> N;
	for(int i=0; i<N; i++) 
		cin >> arrA[i];
	cin >> M;
	
	//퀵정렬로 오름차순 정렬
	qsort(arrA, N, sizeof(int), compare);
	
	for(int i=0; i<M; i++) {
		int x;
		cin >> x;
		cout << BinarySearch(0, N-1, x) << "\n";
		
		//바텀업 방식 
//		int lo = 0, hi = N;
//		bool ck = false;
//		
//		while(lo < hi) {
//			int mid = (lo+hi) / 2;
//			//mid와 같으면 ck 를 true로 하여 출력 
//			if(arrB[i] == arrA[mid]) {
//				ck = true;
//				break;
//			}
//			
//			if(arrB[i] > arrA[mid]) lo = mid+1;
//			else hi = mid;
//		}
	}
	
	cin >> N;
	

	return 0;
}
