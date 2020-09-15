#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <deque>

using namespace std;
int arr[101][101];
int num = 1;
int n, m;

void fill_digit(int x, int y) {
	while (x >= 0 && x < m && y >= 0 && y < n) {
		arr[x][y] = num;
		num++;
		x--;
		y++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 세로 가로 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x = i;
		int y = 0;
		fill_digit(x, y);
	}
	for (int j = 1; j < n; j++) {
		int x = m - 1;
		int y = j;
		fill_digit(x, y);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[j][i] << ' ';
		cout << '\n';
	}

}
