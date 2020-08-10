#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int arr[30001] = { 0, };
int main(void) {
	int n;
	int res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		int cur = arr[i];
		int tmp = 0;
		for (int j = i + 1; j < n; j++) {
			if (cur > arr[j])	tmp++;
			else if (cur < arr[j]) break;
		}
		res = max(tmp, res);
	}
	printf("%d", res);
}
