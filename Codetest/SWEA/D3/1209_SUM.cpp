#include <iostream>

#define ARR_MAX 100

using namespace std;

//함수 사용을 위해 전역 배열 사용 
int arr[ARR_MAX][ARR_MAX];
int row_max;
int col_max;
int m_dia_max;
int s_dia_max;

//가로 합 중 최대값 반환 
int row() {
	row_max = 0;
	for(int i=0 ; i<ARR_MAX; i++) {
		int row_temp = 0;
		for(int j=0; j<ARR_MAX; j++) {
			row_temp += arr[j][i];
		}
		if(row_temp > row_max) row_max = row_temp;
	}
	
	return row_max;
}

//세로 합 중 최대값 반환 
int col() {
	col_max = 0;
	for(int i=0 ; i<ARR_MAX; i++) {
		int col_temp = 0;
		for(int j=0; j<ARR_MAX; j++) {
			col_temp += arr[i][j];
		}
		if(col_temp > col_max) col_max = col_temp;
	}
	
	return col_max;
}

//주대각선 반대각선의 합 반환 
int dia() {
	m_dia_max = 0;
	s_dia_max = 0;
	for(int i=0 ; i<ARR_MAX; i++) {
		for(int j=0; j<ARR_MAX; j++) {
			if(i==j) 
				m_dia_max+=arr[j][i];
			if(i+j == ARR_MAX-1) 
				s_dia_max +=arr[j][i];
		}
	}
	
	cout << "m_dia_max : " << m_dia_max << endl;
	cout << "s_dia_max : " << s_dia_max << endl;
	
	return m_dia_max, s_dia_max;
}

int main(int argc, char** argv) {
	for(int t=1; t<=10; t++) {
		//테스트 케이스 INPUT 
		int T;
		cin >> T;
		int result = 0;
		
		
		//ARR INPUT 
		for(int i=0 ; i<ARR_MAX; i++) {
			for(int j=0; j<ARR_MAX; j++) {
				cin >> arr[j][i];
			}
		}
		
		//row maximum sum
		row_max = row();
		//col maximum sum
		col_max = col();
		//diagnomial maximum
		m_dia_max, s_dia_max = dia();
		
		//solve maximum
		if(result < row_max) result = row_max;
		if(result < col_max) result = col_max;
		if(result < m_dia_max) result = m_dia_max;
		if(result < s_dia_max) result = s_dia_max;
		
		//Test OUTPUT
		cout << row_max << endl;
		cout << col_max << endl;
		cout << m_dia_max << endl;
		cout << s_dia_max << endl;
		
		//OUTPUT 
		cout << "#"<<T<<" "<< result << endl;
	}


	return 0;
}
