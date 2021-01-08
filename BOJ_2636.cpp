#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n, m;
int arr[101][101];
bool visited[101][101] = { false, };
queue<pair<int, int>>q;
queue<pair<int, int>> air;
int cnt = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y])
		return true;
	return false;
}

void InitVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs() {
	InitVisited();
	air.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!air.empty()) {
		int x = air.front().first;
		int y = air.front().second;
		air.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsRange(nx, ny)) {
				// 외부 공기는 air에 넣음
				if (arr[nx][ny] == 0) {
					air.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
				// 외부 공기와 접촉하는 치즈
				if (arr[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int cheese = 0;

	while (1) {
		// 외부 공기 
		bfs();
		// 지울 치즈가 없으면
		if (q.empty()) {
			cout << cnt << '\n';
			cout << cheese ;
			return 0;
		}
		else {
			cheese = 0;
			cnt++;
		}
		while (!q.empty()) {
			int x = q.front().first; int y = q.front().second;
			// 치즈를 공기로 바꿈
			arr[x][y] = 0;
			q.pop();
			cheese++;
		}
	}
}
