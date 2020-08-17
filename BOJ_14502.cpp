#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int arr[10][10] = { 0, };
int tmp[10][10] = { 0, };
bool visited[10][10] = { false, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int res = 0;
int n, m;

int cnt = 0;

void bfs() {
	// bfs는 무조건 queue 사용하자 ! 
	queue <pair<int,int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {

		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (tmp[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					tmp[nx][ny] = 2;
				}
			}
		}
	}
	int save = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0)
				save++;
		}
	}
	cnt++;
	res = max(res, save);
}


void dfs(int x,int y, int cnt) {
	//cout << x << ' ' << y << ' ' << cnt << endl;
	if (cnt == 3) {
		// 벽 세워보기 위해서 tmp에 arr 값 복사
		for (int i = x; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
		bfs();
		return;
	}
	else {
		// i는 x부터 
		// j는 y부터 하면 안됨 왜 ? !
		// 두번째 예제에서
		// -> 만약에 (0,2) 가 시작점이고 cnt=2이면 
		// (1,1)도 선택이 되어야한다 ! 
		// 하지만 j=y라고 하면 두번째 줄에서도 
		// y idx는 2부터 시작될 것이다 
		// 따라서 이차원의 올바른 조합이 아니다.

		for (int i = x; i < n; i++) {
			for (int j = y; j < m; j++) {
				// 어차피 아래서 정해진 값은
				// 1로 바뀌었기 때문에
				// 제외한 나머지 값에 대해서 벽을 세우면서 진행
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					dfs(i,j,cnt + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}

int main(void) {
	// dfs 사용해서 3개의 점 선택 (벽을 만들기)
	// 선택 후 모든 점에 대해서 bfs 진행
	// 최대 안전 영역 구하기

	// 세로, 가로
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << cnt;
	//cout << res;

}
