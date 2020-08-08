#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>

using namespace std;
int arr[10001] = { 0, };
queue <int> q;

int main() {
	long long n, m;
	cin >> n >> m;
	// 1 2 3 4 2 5 3 1 1 2
	// 1
	// 1 2
	// 1 2 3
	// 2 3
	// 2 3 4
	// 3 4
	// 4
	// 4 2
	// 2
	// 2 5
	// 5
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int res = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		q.push(val);
		sum += val;
		// sum이 크면 반복해라 !!
		while (sum > m) {
			if (!q.empty()) {
				sum -= q.front();
				q.pop();
			}
			else
				break;
		}
		// 작거나 같을 때까지 계속해서 빼고 
		// 같으면 res++
		// 아니면 새로운 값을 넣어서 또 확인한다.
		if (sum == m)
			res++;
	}
	cout << res;

}
