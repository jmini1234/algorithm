#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>

using namespace std;
int arr[1000001];
int n;
int b, c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int tmp = arr[i];
		if (tmp <= b) {
			res++;
			continue;
		}
		else {
			tmp -= b;
			res++;
			if (tmp <= c) {
				res++;
				continue;
			}
			if (tmp%c == 0)
				res += tmp / c;
			else
				res += tmp / c + 1;
		}
	}
	cout << res;

}
