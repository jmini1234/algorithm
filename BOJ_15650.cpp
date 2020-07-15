#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>
#include <vector>

using namespace std;

int arr[10] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;
  // 순열을 위해 입력 받는 수를 각각 1로 나눈 배열을 만든다.
	for (int i = 0; i < m; i++) {
		arr[i] = 1;
	}
	do {
		for (int i = 0; i < n; i++) {
      // 선택된 값이면
			if (arr[i] == 1)
				cout << i+1 << ' ';
		}
		cout << '\n';
    // 1이 먼저있는 배열이기 때문에 prev_permu 사용 
	} while (prev_permutation(arr, arr + n));
	cin >> n;
}
