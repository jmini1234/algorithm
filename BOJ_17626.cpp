#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int sum = 0;
	int dp[50001] = { 0, };
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int min_val = 100000;
		for (int j = 1; j*j <= i; j++) {
			min_val = min(dp[i - j*j], min_val);
		}
		dp[i] = min_val + 1;
	}
	cout << dp[n];
}
