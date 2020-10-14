#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int t;
int n, K;
int arr[10][10];
bool visited[10][10];
int tmp[10][10];
int total = 0;
bool used = false;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	}
}
bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

// 딱 한 곳의 K 깊이만큼 깎을 수 있음
// 계속해서 길이를 증가시키는데 바로 전 값과 비교하면서 진행한다.
void getSize(int x, int y, int prev, int cnt) {
	// total 값은 함수 호출시 계속 갱신한다 !!!!
	total = max(total, cnt);
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (IsRange(nx, ny) && !visited[nx][ny]) {
			// 이전 값보다 작다면 계속 진행 가능
			if (arr[nx][ny] < prev) {
				visited[nx][ny] = true;
				getSize(nx, ny,arr[nx][ny], cnt+1);
				visited[nx][ny] = false;
			}
			if (arr[nx][ny]>= prev && !used) {
				// K까지 자를 수있으니까 모든 경우의 수를 다 해봐야한다
				// 언제가 최고 길이가 나올 수 있을지 모르기 때문에
				for (int i = 1; i <= K; i++) {
					if (arr[nx][ny] - i < prev) {
						used = true;
						visited[nx][ny] = true;
						getSize(nx, ny, arr[nx][ny] - i, cnt + 1);
						visited[nx][ny] = false;
						used = false;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> K;
		total = 0;
		// 방문 여부 초기화
		initVisited();
		int max_val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (max_val < arr[i][j])
					max_val = arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == max_val && !visited[i][j]) {
					visited[i][j] = true;
					getSize(i, j, arr[i][j], 1);
					visited[i][j] = false;
				}
			}
		}

		cout << total;
	}
}
