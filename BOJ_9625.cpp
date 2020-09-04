#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
# define MOD 1000000000;
using namespace std;
int dp[50][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	// A의 개수
	dp[0][0] = 1;
	// B의 개수
	dp[0][1] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i][0] += dp[i - 1][1];
		dp[i][1] += dp[i - 1][0] + dp[i - 1][1];
	}

	cout << dp[n][0] << ' ' << dp[n][1];

}
