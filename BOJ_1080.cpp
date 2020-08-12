#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int A[51][51];
int B[51][51];

int n, m;

void filp(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 0)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
}

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0')
				A[i][j] = 0;
			else
				A[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0')
				B[i][j] = 0;
			else
				B[i][j] = 1;
		}
	}
	int res = 0;
	if (n >= 3 && m >= 3) {
		for (int i = 0; i <= n-3; i++) {
			for (int j = 0; j <= m-3; j++) {
				if (A[i][j] != B[i][j]) {
					filp(i, j);
					res++;
				}
			}
		}
	}
	else {
		if (check()) {
			cout << 0 << endl;
			return 0;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	if (check())
		cout << res;
	else
		cout << -1;
}
