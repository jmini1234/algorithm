#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
# define MOD 1000000000;
using namespace std;
int dp[1001];
int arr[1001];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	// dp 배열이 정확히 무슨 값을 저장하는지 말로 정의하기 
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i-j] + arr[j]);
		}
	}
	cout << dp[n];

}
