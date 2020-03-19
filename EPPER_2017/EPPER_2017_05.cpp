#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int arr[10][10];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 전치행렬 출력하기 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
}
