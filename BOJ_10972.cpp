#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>
#include <vector>

using namespace std;

int arr[10001] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (next_permutation(arr, arr + n))
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
	else
		cout << -1;
}
