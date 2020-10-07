#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int arr[201][201];
bool visited[201][201];
vector <pair<int, int>> hos;
vector <pair<int, int>> res;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool flag = false;
int min_val = INT_MAX;

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

bool RemoveVirus(int arrcnt[201][201]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 바이러스인데 갱신 안됐음
			if (arrcnt[i][j] == 0 && arr[i][j] == 0)
				return false;
		}
	}
	return true;
}
void visitedInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	}
}
void selectHos(int idx) {
	if (res.size() == m) {
		// 동시에 갱신해야함
		int arrcnt[201][201];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arrcnt[i][j] = 0;
			}
		}
		// visited 초기화

		visitedInit();
		queue <pair<int, int>> q;
		// m개의 병원 선택 (시작점이 같기 때문에 한번에 넣자)
		for (int i = 0; i < m; i++)
			q.push(make_pair(res[i].first, res[i].second));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				// 범위안에 있고 바이러스이면 계속
				// 병원이어도 계속 ,,,
				if ((IsRange(nx, ny) && (arr[nx][ny] == 0 || arr[nx][ny]==2) && !visited[nx][ny])) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					// 같은 속도로 진행되기 때문에 최솟값이 나온다.
					arrcnt[nx][ny] = arrcnt[x][y] + 1;
				}
			}
		}
		// 이미 모든 바이러스가 삭제됨
		if (RemoveVirus(arrcnt)) {
			flag = true;
			int max_val = 0;
			// 바이러스 중 최댓값 갱신
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 0 && arrcnt[i][j] > max_val)
						max_val = arrcnt[i][j];
				}
			}
			if (max_val < min_val)
				min_val = max_val;
		}
		return;
	}
	for (int i = idx + 1; i < hos.size(); i++) {
		res.push_back(hos[i]);
		selectHos(i);
		res.pop_back();
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			// 병원
			if (arr[i][j] == 2) {
				hos.push_back(make_pair(i, j));
			}
		}
	}

	selectHos(-1);

	if (flag)
		cout << min_val;
	else
		cout << -1;

}
