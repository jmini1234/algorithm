#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <deque>

using namespace std;
int res = 0;
int k;
int arr[3] = { 0, };

void solve(int index, int sums) {

	// 마지막까지 왔을때 지금까지 더한 값이 k와 같은지 비교
	if (index == 3) {
		if (sums == k) {
			res++;
		}
		return;
	}

	// 해당 원소 더할 때
	solve(index + 1, sums + arr[index]);
	// 해당 원소 더하지 않을 때
	solve(index + 1, sums);
}

int main() {

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	cin >> k;

	// 다 더한 값이 0일때는 공집합이 포함되기 때문에 -1 해준다. (즉 아무것도 안 더한 상태일때)
	if (k == 0)
		res--;


	// 재귀 함수
	solve(0, 0);

	cout << res;
}

