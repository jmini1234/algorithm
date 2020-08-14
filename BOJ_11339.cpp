#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001] = { 0, };
int res[1001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	res[0] = arr[0];
	int sum = res[0];
	for (int i = 1; i < n; i++) {
		res[i] = res[i - 1] + arr[i];
		sum += res[i];
	}

	cout << sum;


}
