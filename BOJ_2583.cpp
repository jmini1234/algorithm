#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n, m, k;
int arr[101][101] = { 0, };
bool visited[101][101] = { false, };
vector<int> res;
int area = 0;
int dx[4] = { -1,1,0,0, };
int dy[4] = { 0,0,-1,1 };

bool IsRight(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y]==0 && !visited[x][y])
		return true;
	return false;
}

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (IsRight(nx, ny)) {
				visited[nx][ny] = true;
				cnt++;
				q.push(make_pair(nx, ny));
			}
		}
	}
	res.push_back(cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				visited[i][j] = true;
				area++;
				bfs(i, j);
			}
		}
	}
	cout << area << '\n';
	sort(res.begin(), res.end());
	for (auto &k : res)
		cout << k << ' ';
}
