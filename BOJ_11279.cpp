#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, less<int>> my_pq;

	int n;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		if (val == 0) {
			if (my_pq.empty())
				cout << 0 << '\n';
			else {
				cout << my_pq.top() << '\n';
				my_pq.pop();
			}
		}
		else {
			my_pq.push(val);
		}
	}
}
