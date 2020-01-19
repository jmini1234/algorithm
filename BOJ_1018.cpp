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
