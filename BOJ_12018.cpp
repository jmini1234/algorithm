#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional> // greater사용하기 위해

using namespace std;
bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, total;
	cin >> n >> total;

	vector <int> v;

	for(int i=0;i<n;i++)
	{
		// 최소 힙
		priority_queue <int, vector<int>, greater<int>> my_pq;
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			int val;
			cin >> val;
			my_pq.push(val);
		}
		// 마일리지 1만 적용
		if (a < b) {
			v.push_back(1);
		}
		else {
			// 초과된 학생 수
			int gap = a - b;
			while (gap != 0) {
				my_pq.pop();
				gap -= 1;
			}
			int my = my_pq.top();
			v.push_back(my);
		}
	}

	int res = 0;

	sort(v.begin(), v.end());

	for (auto &k : v) {
		if (total >= k)
		{
			total -= k;
			res++;
		}
		else {
			break;
		}
	}
	cout << res << '\n';
}
