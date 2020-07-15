#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>
#include <vector>

using namespace std;


int main() {
	int n;
	do {
		int arr[50] = { 0, };
		int permu[50] = { 0, };

		cin >> n;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			arr[i] = val;
		}
		for (int i = 0; i < 6; i++) {
			permu[i] = 1;
		}
		do {
			for (int i = 0; i < n; i++) {
				if (permu[i] == 1) {
					cout << arr[i] << ' ';
				}
			}
			cout << '\n';
		} while (prev_permutation(permu, permu + n));
	cout << '\n';
	} while (n != 0);
}
