#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
using namespace std;
int n, m;
int arr[51][51];
bool visited[51][51];
vector<pair<int, int>> v;
vector < pair<int, int>> res;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int min_val = INT_MAX;
bool flag = false;
int t = 0;

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

bool IsVirus(int tmp[51][51], bool Bvisited[51][51]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] != -1 && !Bvisited[i][j])
				return false;
		}
	}
	return true;
}

void dfs(int idx) {
	if (res.size() == m) {
		// tmp 배열 및 vistied 배열 초기화 (BFS에서는 중요)
		int tmp[51][51];
		bool Bvisited[51][51] = { false, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 2)
					// 바이러스 놓을 수 있는 장소 일단 0으로
					tmp[i][j] = 0;
				if (arr[i][j] == 1)
					// 벽
					tmp[i][j] = -1;
				else
					// 그렇지 않으면 0으로 !
					tmp[i][j] = 0;
			}
		}
		queue <pair<int, int>> q;
		for (auto &k : res) {
			int x = k.first;
			int y = k.second;
			// 가중치 동일하게 똑같이 시작해야함.
			Bvisited[x][y] = true;
			q.push(make_pair(x, y));
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (IsRange(nx, ny) && !Bvisited[nx][ny] && tmp[nx][ny]!=-1) {
					q.push(make_pair(nx, ny));
					Bvisited[nx][ny] = true;
					tmp[nx][ny] = tmp[x][y] + 1;
				}
			}
		}
		// 다 퍼졌다면 
		if (IsVirus(tmp, Bvisited)) {
			int tmp_max = 0;
			flag = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					tmp_max = max(tmp_max, tmp[i][j]);
				}
			}
			min_val = min(min_val, tmp_max);
		}
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		visited[x][y] = true;
		res.push_back(make_pair(x, y));
		dfs(i + 1);
		visited[x][y] = false;
		res.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	// dfs로 배열의 2의 위치에 바이러스를 놓는다. 
	// 그 후 bfs로 바이러스를 각각 퍼트린다. 
	// max값을 구해서 최소의 시간을 반환한다.
	// 만약 빈칸이지만 바이러스가 침투 안된 곳이 있으면
	// -1을 반환한다.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back(make_pair(i, j));
		}
	}

	dfs(0);

	if (flag)
		cout << min_val;
	else
		cout << -1;

}
