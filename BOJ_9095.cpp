#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <deque>

using namespace std;
int arr[12] = { -1, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1 || n == 2 || n == 3)
			cout << arr[n] << '\n';
		else {
			for (int i = 4; i <= n; i++) {
				arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
			}
			cout << arr[n] << '\n';
		}
	}

}
