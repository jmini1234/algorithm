#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <deque>

using namespace std;
int direction = 0;
int n, m;
char arr[101][101];
bool visited[101][101] = { false, };
int dx[4] = {1,0,-1,0 };
int dy[4] = { 0, 1,0,-1 };
// 방향 0,1,2,3
// 각각
char alpa = 'A';
bool canGo(int x, int y) {
	if (x < m && x >= 0 && y < n && y >= 0 && !visited[x][y])
		return true;
	else
		return false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	arr[0][0] = alpa;
	visited[0][0] = true;
	int currentX = 0;
	int currentY = 0;
	for (int i = 0; i < n*m; i++) {
		while (1) {
			int xn = currentX + dx[direction];
			int yn = currentY + dy[direction];
			if (canGo(xn, yn)) {
				alpa++;
				if (alpa > 'Z')
					alpa = 'A';
				arr[xn][yn] = alpa;
				visited[xn][yn] = true;
				currentX = xn;
				currentY = yn;
			}
			else {
				direction++;
				if (direction == 4)
					direction = 0;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[j][i] << ' ';
		cout << '\n';
	}
}
