#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char arr[50][50];

	char answer1[8][8] = {
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W'
	};

	char answer2[8][8] = {
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int res = 70;
	int tmp1,tmp2;

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			tmp1 = 0;
			tmp2 = 0;
			
				for (int k = i; k < 8 + i; k++) {
					for (int l = j; l < 8 + j; l++) {
						if (arr[k][l] != answer1[k - i][l - j])
							tmp1++;
					}
				}
		
				for (int k = i; k < 8 + i; k++) {
					for (int l = j; l < 8 + j; l++) {
						if (arr[k][l] != answer2[k - i][l - j])
							tmp2++;
					}
				}

				int cmp = min(tmp1, tmp2);
				if (cmp < res)
					res = cmp;
		}
	}
	printf("%d", res);

}

///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
vector<string> v(50);
int res = 1000000;
// 비교할 체스
vector<string> chess = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW",
						"WBWBWBWB","BWBWBWBW", "WBWBWBWB","BWBWBWBW",
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cnt = 0;
			for (int dx = 0; dx < 8; dx++) {
				for (int dy = 0; dy < 8; dy++) {
					if (chess[dx][dy] != v[i + dx][j + dy])
						cnt++;
				}
			}
			int tmpmin = min(cnt, 64 - cnt);
			res = min(res, tmpmin);
		}
	}
	cout << res;
}
