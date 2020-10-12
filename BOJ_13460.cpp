#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <functional>
#include <iostream>
using namespace std;
int n, m;
char arr[11][11];
// 좌, 우, 하, 상
// 1, 3 는 오 -> 왼 (뒤에서부터)
// 0, 2 은 왼 -> 오 (앞에서부터)
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int res = 11;

bool IsRed() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'R')
				return true;
	}
	return false;
}

bool IsBlue() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'B')
				return true;
	}
	return false;
}

bool CanGo(int x, int y) {
	return arr[x][y] == '.' || arr[x][y] == 'O';
}

void move(int x, int y, int dir) {
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		// 다른 사탕이 있을수도 있기 때문에
		if (arr[nx][ny] == '#' || arr[nx][ny] == 'B' || arr[nx][ny]=='R')
			break;
		if (arr[nx][ny] == 'O') {
			arr[x][y] = '.';
			break;
		}
		// 한킨씩 사탕 이동하기
		arr[nx][ny] = arr[x][y];
		arr[x][y] = '.';
		x = nx;
		y = ny;
	}
}

void rotate(int dir) {
	// dir에 따라 각 구슬이 움직이는 방향이 다르다.
	if (dir % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 'B' || arr[i][j] == 'R') {
					move(i, j, dir);
				}
			}
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				// 해당 위치에 구슬이 있다면 dir 방향으로 옮기기
				if (arr[i][j] == 'B' || arr[i][j] == 'R') {
					move(i, j, dir);
				}
			}
		}
	}
}

void backtracking(int cnt) {
	// 파란공이 없으면
	if (!IsBlue())
		return;
	// 파란공 있고, 빨간공 없을때
	if (!IsRed()) {
		res = min(res, cnt);
		return;
	}
	// 10번째 위에서 검사 후 더 이상 진행 x
	if (cnt >= 10)
		return;
	for (int dir = 0; dir < 4; dir++) {
		// 한 번 회전하기 전 값을 저장한다.
		// backtraking 할 때 다시 이전의 값으로 돌아와야하기 때문에
		int tmp[11][11];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				tmp[i][j] = arr[i][j];
		}
		rotate(dir);
		backtracking(cnt + 1);
		// 다시 다른 방향으로 돌려보기 위해 arr를 원래 값으로 돌려놓는다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				arr[i][j] = tmp[i][j];
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	// 모든 경우의 수 진행해야한다.
	// 상 -> 상 -> 상하좌우
	//       하 -> 상하좌우
	//       좌 -> 상하좌우
	//       우 -> 상하좌우
	backtracking(0);

	if (res != 11)
		cout << res;
	else
		cout << -1;
}
