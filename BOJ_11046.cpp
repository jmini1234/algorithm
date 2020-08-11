#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n;
long long k;
int arr[100];

int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k / arr[i] != 0) {
			res += k / arr[i];
			k %= arr[i];
			if (k == 0) {
				cout << res;
				return 0;
			}
		}
	}
	cout << res;
	
}
