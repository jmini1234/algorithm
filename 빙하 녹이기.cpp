#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int arr[201][201];
bool visited[201][201];
int Icetime;
vector <int> IceSpace;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int getSize() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1)
				res++;
		}
	}
	return res;
}

void bfs() {
	Icetime++;
	queue <pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	}
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (IsRange(nx, ny) && arr[nx][ny]==0 && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (IsRange(nx, ny) && arr[nx][ny] == 0 && visited[nx][ny]) {
						arr[i][j] = 0;
						break;
					}
				}
			}
		}
	}

	int Ice = getSize();
	//cout << Ice << endl;
	if (Ice == 0) {
		cout << Icetime << ' ' << IceSpace.back();
		exit(0);
	}
	IceSpace.push_back(Ice);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	IceSpace.push_back(getSize());

	while (1) {
		bfs();
	}


}
