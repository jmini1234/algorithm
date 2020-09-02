#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int arr[1010];
int res[1010] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// 40 20 60 10 40 50
	// 1  1   2  0 3 
	// 40 20 20 10 10 10 
	int min_val = arr[0];
	int max_res = 1;
	for (int i = 1; i <= n; i++) {
		res[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (res[j] + 1 > res[i])
					res[i] = res[j] + 1;
			}
		}
		if (res[i] > max_res)
			max_res = res[i];
	}
	cout << max_res;

}
