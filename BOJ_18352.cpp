#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, k, start;
vector<int> res;
vector<int>v[300001];
// visited와 거리 같이 저장
vector<int>dist(300001, INT_MAX);
queue<int> q;


void bfs() {
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 0; i < v[idx].size(); i++) {
			if (dist[v[idx][i]] == INT_MAX) {
				dist[v[idx][i]] = dist[idx] + 1;
				q.push(v[idx][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k >> start;
	for (int i = 0; i < m; i++) {
		int citystart, cityend;
		cin >> citystart >> cityend;
		v[citystart].push_back(cityend);
	}

	dist[start] = 0;
	q.push(start);
	bfs();

	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			res.push_back(i);
		}
	}

	sort(res.begin(), res.end());

	if (res.size() == 0)
		cout << -1;
	else {
		for (auto&k : res)
			cout << k << '\n';
	}
}
