#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	string num;
	cin >> num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	}
	cout << sum;
}
