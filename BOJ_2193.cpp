#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
long long arr[100][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	// 1           / 1 0
	// 10          / 0 1
	// 100, 101    / 1 1 
	// 1000, 1001, 1010    / 1 2
	// 10000 10001 10010 10100 10101 / 2 3
	// 2+3*2
	// 0또는 1이 추가되는 성질이 있다.
	arr[0][0] = 1; // 1로 끝나는 수의 개수
	arr[0][1] = 0; // 0으로 끝나는 수의 개수
	for (int i = 1; i < n; i++) {
		arr[i][0] += arr[i - 1][1];
		arr[i][1] += arr[i - 1][1];
		arr[i][1] += arr[i - 1][0];
	}
	cout << arr[n - 1][0] + arr[n - 1][1];

}
