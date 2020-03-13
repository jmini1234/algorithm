#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int N, r, c;

char arr[3000][3000];

void init() {
	for (int i = 0; i < 3000; ++i) {
		for (int j = 0; j < 3000; ++j) {
			arr[i][j] = ' ';
		}
	}
}

void solve(int size, int x, int y) {
	int print_size = size / 3;

	//size가 1일때 *을 넣는다.
	if (size == 1) {
		arr[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// idx가 (1,1)이면 수행하지 않는다. 
			if (i == 1 && j == 1)
				continue;
			// 그렇지 않으면 사이즈 줄여서 호출 
			solve(print_size, x + (print_size*i), y + (print_size*j));
		}
	}
	return;

}

int main()
{

	cin >> N;

	init();
	solve(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	

}
