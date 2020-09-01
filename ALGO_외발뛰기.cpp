#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int arr[101][101];
int cache[101][101] = { -1, };
int n;

bool cal(int x,int y) {
	//cout << x << ',' << y << '\n';
	if (x == n - 1 && y == n - 1) {
		// 참
		return 1;
	}
	if (x >= n || y >= n) {
		// 거짓
		return 0;
	}
	// 이미 방문된 곳일 때
	if (cache[x][y] != -1)
		return cache[x][y];
	cache[x][y] = (cal(x, y + arr[x][y]) || cal(x + arr[x][y], y));
	return cache[x][y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int c;
	cin >> c;
	for(int i=0;i<c;i++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cache[i][j] = -1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		if (cal(0,0))
			cout << "YES"<<'\n';
		else
			cout << "NO" << '\n';
	}

}
