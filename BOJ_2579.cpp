#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
long long dp[301];
int arr[301];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	// 계단 1개 또는 2개
	// 연속 세개 x
	// 마지막 필수 !
	// dp에 마지막 계단이 포함됐을 때 최대값
	// 10
	// 10 20
	// 20 15
	// 10 20 25
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= n; i++) {
		
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1]+arr[i]);
			
	}
	cout << dp[n];
	

}
