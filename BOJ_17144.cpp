#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int R, C, T;
int arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int s1, e1, s2, e2;

bool IsRange(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C)
		return true;
	return false;
}

void wind() {
	int tmp[51][51] = { 0, };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] >0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (IsRange(nx, ny) && arr[nx][ny] != -1) {
						tmp[nx][ny] += arr[i][j] / 5;
						cnt++;
					}
				}
				tmp[i][j] += (arr[i][j] - (arr[i][j] / 5)*cnt);
				arr[i][j] = 0;
			}
			else if (arr[i][j] == -1) {
				tmp[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			arr[i][j] = tmp[i][j];
	}
}

void move1() {
	int dir = 0;
	int x = s1, y = e1+1;
	int ddx[4] = { 0,-1,0,1 };
	int ddy[4] = { 1,0,-1,0 };
	int tmp[51][51];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			tmp[i][j] = arr[i][j];
	}
	arr[x][y] = 0;
	while (1) {
		int tx = x + ddx[dir];
		int ty = y + ddy[dir];
		if (tx == s1 && ty == e1)
			break;
		if (IsRange(tx, ty)) {
			arr[tx][ty] = tmp[x][y];
			x = tx, y = ty;
		}
		else
			dir = (dir + 1) % 4;
	}
}

void move2() {
	int dir = 0;
	int x = s2, y = e2 + 1;
	int ddx[4] = { 0,1,0,-1 };
	int ddy[4] = { 1,0,-1,0 };
	int tmp[51][51] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			tmp[i][j] = arr[i][j];
	}

	arr[x][y] = 0;

	while (1) {
		int tx = x + ddx[dir];
		int ty = y + ddy[dir];
		if (tx == s2 && ty == e2)
			break;
		if (IsRange(tx, ty)) {
			arr[tx][ty] = tmp[x][y];
			x = tx, y = ty;
		}
		else
			dir = (dir + 1) % 4;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	int total = 0;
	vector<pair<int, int>> machine;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				machine.push_back(make_pair(i, j));
		}
	}
	s1 = machine[0].first;
	e1 = machine[0].second;
	s2 = machine[1].first;
	e2 = machine[1].second;

	while (T--) {
		wind();
		move1();
		move2();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != -1)
				total += arr[i][j];
		}
	}
	cout << total;
}
