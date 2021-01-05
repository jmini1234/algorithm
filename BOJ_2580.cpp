#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int arr[10][10];

bool IsEnd() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool isRight(int x, int y) {
	int val = arr[x][y];
	for (int i = 0; i < 9; i++) {
		if (i != y && arr[x][i] == val)
			return false;
	}
	for (int j = 0; j < 9; j++) {
		if (j != x && arr[j][y] == val)
			return false;
	}
	// 0-2/ 3-5/ 6-8 
	int xsize = 3 * (x / 3);
	int ysize = 3 * (y / 3);

	for (int i = xsize; i < xsize + 3; i++) {
		for (int j = ysize; j < ysize + 3; j++) {
			if (i != x && j != y && arr[i][j] == val)
				return false;
		}
	}
	return true;


}

void dfs() {

	if (IsEnd()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			// 채워야하는 곳이면 채우기
			if (arr[i][j] == 0) {
				for (int num = 1; num <= 9; num++) {
					arr[i][j] = num;
					if (isRight(i, j)) {
						dfs();
					}
					arr[i][j] = 0;
				}
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}
	dfs();
}
