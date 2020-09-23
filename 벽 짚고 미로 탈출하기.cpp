#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

int n, currentX, currentY;
char arr[101][101];
// 각 방향별로 방문 여부 저장
bool visited[101][101][4] = { false, };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int currentDir = 0;
int res = 0;

bool InRange(int x, int y) {
	if (x > 0 && x <= n && y > 0 && y <= n)
		return true;
	return false;
}

void Simulate() {
	// 같은 방향으로 이미 방문한 곳이 있을 때
	if (visited[currentX][currentY][currentDir]) {
		cout << -1;
		exit(0);
	}
	// 없으면 방문 true
	visited[currentX][currentY][currentDir] = true;
	// 일단 현재 방향으로 가기
	int x = currentX + dx[currentDir];
	int y = currentY + dy[currentDir];
	// 만약 벽이 있으면
	if (InRange(x,y) && arr[x][y] == '#') {
		// 방향 바꾸기
		currentDir = (currentDir - 1 + 4) % 4;
	}
	// 밖으로 나갔으면
	else if (!InRange(x,y)) {
		// 끝
		cout << res + 1;
		exit(0);
	}
	// 없으면 x,y 아래 칸이 있는지 없는지 확인해야함.
	else {
		int nx = x + dx[(currentDir + 1) % 4];
		int ny = y + dy[(currentDir + 1) % 4];
		// 계속 갈 수 있다면 !
		if (arr[nx][ny] == '#') {
			currentX = x;
			currentY = y;
			res++;
		}
		else {
			currentDir = (currentDir + 1) % 4;
			currentX = nx;
			currentY = ny;
			res += 2;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> currentX >> currentY;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}

	while (1) {
		Simulate();
	}
}
