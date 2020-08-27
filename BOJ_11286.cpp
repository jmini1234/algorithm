#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional> // greater사용하기 위해

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> my_pq;

	int n;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		if (val == 0) {
			if (my_pq.empty())
				cout << 0 << '\n';
			else {
				cout << my_pq.top().second << '\n';
				my_pq.pop();
			}
		}
		else {
			if (val < 0)
				my_pq.push(make_pair(-val, val));
			else
				my_pq.push(make_pair(val, val));
		}
	}
}
