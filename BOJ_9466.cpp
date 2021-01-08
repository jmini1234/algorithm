#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int t, n;
vector<bool>visited;
vector<bool>cycle;
vector<int>v;
vector<int> res;
int cnt;

void dfs(int start) {
	visited[start] = true;
	int next = v[start];

	if (!visited[next]) {
		dfs(next);
	}
	else {
		if (!cycle[next]) {
			for (int i = next; i != start; i = v[i])
				cnt++;
			cnt++;
		}
	}
	cycle[start] = true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 0;
		v = vector<int>(n + 1, 0);
		visited = vector<bool>(n+1, false);
		cycle = vector<bool>(n + 1, false);

		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				// 시작점과 다음점
				dfs(i);
			}
		}
		cout << n-cnt << '\n';
	}

}
