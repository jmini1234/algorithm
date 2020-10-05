#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int max_num = 0;
int res = 0;

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

void dfs(int x, int y, int k) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsRange(nx, ny) && arr[nx][ny] > k && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, k);
		}
	}
}

void cal(int k) {
	// k 가 변할 때마다 초기화
	res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > k && !visited[i][j]) {
				res++;
				visited[i][j] = true;
				dfs(i, j, k);
			}
		}
	}
}

int main() {
	int max_val = -1;
	int max_k = 0;
	// k를 늘려가면서 결과 값을 저장
	// 안전영역의 크기가 0이 되면 stop !
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max_num)
				max_num = arr[i][j];
		}
	}

	for (int k = 1; k <= max_num; k++) {
		cal(k);
		if (res > max_val) {
			max_val = res;
			max_k = k;
		}
	}
	cout << max_k << ' ' << max_val;
}
