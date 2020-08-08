#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;
// 5 2 0 0 0 0 4 0 0 0 0 0 0 0 10
// 1차원 배열이지만 좌우로 K만큼 !
// for 문 사용하면 시간초과 
// K가 주어졌으면 저장되는 값 2K+1로 고정
int arr[1000001] = { 0, };

int main() {
	// N, Z, M
	int N, K;
	cin >> N >> K;
	queue <int> q;
	int max = 0;
	int i = 0;
	int sum = 0;

	while (N--) {
		int val, idx;
		cin >> val >> idx;
		arr[idx] = val;

	}
	while (1) {
		// 다 채워지지 않았다면
		if (i == 1000001)
			break;
		else if (q.size() >= 2 * K + 1) {
			sum -= q.front();
			q.pop();
		}
		q.push(arr[i]);
		sum += arr[i];
		if (sum > max)
			max = sum;
		i++;
	}
	cout << max;


}
