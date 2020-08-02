#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

long long N, K;
vector <long long> arr;

bool check(long long num) {
	long long cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += (arr[i] / num);
	}
	return cnt >= N;
}

long long cal_cm(long long left, long long right) {
	long long ans = 1;
	// 등호는 최대값이 정답이 되는 경우를 고려하기 위해
	while (left <= right) {
		long long mid = (left + right) / 2;
		// N개를 만들 수 있는 최대 길이니까 초과해도 된다.
		// 만들 수 있는 개수가 더 많거나 같으면 크기 늘림
		if (check(mid) == true) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			// right=mid라고 하면 계속 무한루프
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		long long val;
		scanf("%d", &val);
		arr.push_back(val);
	}

	long long max = *max_element(arr.begin(), arr.end());

	// 이분 탐색 이용해서 개수가 N보다 작으면
	// 줄여서 다시 계산 -> 반복
	// max 값부터 넣기
	printf("%d", cal_cm(1, max));
}
