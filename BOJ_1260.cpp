#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, v;

queue <int> dfs_res;
queue <int> bfs_res;

bool check[1001][1001] = { false, };
bool visited[1001] = { false, };
bool b_visited[1001] = { false, };

void dfs(int start) {
	visited[start] = true;
	dfs_res.push(start);
	for (int i = 1; i <= n; i++) {
		if (check[start][i] && !visited[i]) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	b_visited[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int val = q.front();
		bfs_res.push(val);
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (check[val][i] && !b_visited[i]) {
				b_visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> v;
	while (m--) {
		int n1, n2;
		cin >> n1 >> n2;
		check[n1][n2] = true;
		check[n2][n1] = true;
	}
	dfs(v);

	while (!dfs_res.empty()) {
		cout << dfs_res.front();
		if (dfs_res.size() != 1)
			cout << ' ';
		else
			cout << '\n';
		dfs_res.pop();
	}
	
	bfs(v);

	while (!bfs_res.empty()) {
		cout << bfs_res.front();
		if (bfs_res.size() != 1)
			cout << ' ';
		else
			cout << '\n';
		bfs_res.pop();
	}


}
