#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int arr[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				arr[i][j] = min(arr[i][j] + arr[i - 1][j + 1], arr[i][j] + arr[i - 1][j + 2]);
			}
			else if (j == 1) {
				arr[i][j] = min(arr[i][j] + arr[i - 1][j - 1], arr[i][j] + arr[i - 1][j + 1]);
			}
			else {
				arr[i][j] = min(arr[i][j] + arr[i - 1][j - 2], arr[i][j] + arr[i - 1][j - 1]);
			}
		}
	}
	
	int min_res = arr[n - 1][0];
	for (int i = 1; i < 3; i++)
		if (arr[n - 1][i] < min_res)
			min_res = arr[n - 1][i];
	cout << min_res;
}
