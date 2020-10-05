#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int graph[101][101];
int max_val = 0;
vector<pair<int, int>> empty_wall;
vector<pair<int, int>> fire;
vector<pair<int, int>> tmp_wall;

bool visited[101][101];
int res = 0;

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

void bfs(int arr[101][101]) {
	res++;
	// 불이 있는 경우 -> 2
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	queue < pair<int, int>> q;

	for (int i = 0; i < fire.size(); i++) {
		int x = fire[i].first;
		int y = fire[i].second;
		q.push(make_pair(x, y));
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				// 범위안에 있고 빈공간이면
				if (IsRange(next_x, next_y) && arr[next_x][next_y] == 0) {
					q.push(make_pair(next_x, next_y));
					// 불을 넣어준다.
					arr[next_x][next_y] = 2;
				}
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				cnt++;
		}
	}
	max_val = max(cnt, max_val);
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		int tmp_graph[101][101];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				tmp_graph[i][j] = graph[i][j];
		}
		for (auto &k : tmp_wall)
			tmp_graph[k.first][k.second] = 1;

		bfs(tmp_graph);
		return;
	}
	else {
		for (int i = idx + 1; i < empty_wall.size(); i++) {
			tmp_wall.push_back(empty_wall[i]);
			dfs(i, cnt + 1);
			tmp_wall.pop_back();
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0)
				empty_wall.push_back(make_pair(i, j));
			if (graph[i][j] == 2)
				fire.push_back(make_pair(i, j));
		}
	}

	dfs(-1, 0);

	cout << max_val;
}
