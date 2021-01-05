#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int arr[1000001];
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	arr[1] = 0;
	cin >> n;
	if (n == 1 || n == 2 || n == 3)
		cout << arr[n];
	else {
		for (int i = 4; i <= n; i++) {
			int min_val = INT_MAX;
			if (i % 2 == 0) min_val = min(min_val, arr[i / 2] + 1);
			if (i % 3 == 0) min_val = min(min_val, arr[i / 3] + 1);
			min_val = min(min_val, arr[i - 1] + 1);
			arr[i] = min_val;
		}
		cout << arr[n];
	}
}
