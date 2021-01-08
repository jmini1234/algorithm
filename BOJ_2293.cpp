#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n, k;
vector<int>v;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		int coin = v[i];
		for (int j = coin; j <= k; j++) {
			dp[j] += dp[j - coin];
		}
	}

	cout << dp[k];

}
