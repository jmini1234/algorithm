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

	priority_queue < int, vector<int>, greater<int>> my_pq;

	vector <pair<int, int>> v;

	// 기간, 선호도, 종류
	int n, m, k;
	cin >> n >> m >> k;
	int favor = 0;

	for (int i = 0; i < k;i++) {
		// 선호도, 도수
		// 선호도는 높아야하고 도수는 낮아야한다.
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	bool check = false;

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < k; i++) {
		int tmp_fav = v[i].first;
		int tmp_al = v[i].second;
		favor += tmp_fav;
		my_pq.push(tmp_fav);
		// n개 이상 선택될 때 
		if (my_pq.size() > n) {
			favor -= my_pq.top();
			my_pq.pop();
		}
		if (my_pq.size() == n && favor >= m) {
			check = true;
			cout << tmp_al << '\n';
			break;
		}
	}
	if (!check)
		cout << "-1\n";
}
