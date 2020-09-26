#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <math.h>

using namespace std;

int n, m;
int arr[51][51];
vector <pair<int, int>> hos;
vector <pair<int, int>> res;
int min_val = INT_MAX;

int cal(vector<pair<int, int>> v) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				int min_tmp = INT_MAX;
				for (auto &k : v) {
					min_tmp = min(min_tmp, abs(k.first - i) + abs(k.second - j));
				}
				res += min_tmp;
			}
		}
	}
	return res;
}

void choose(int idx, int cnt) {
	if (cnt == m) {
		min_val = min(min_val, cal(res));
		return;
	}
	for (int i = idx + 1; i < hos.size(); i++) {
		res.push_back(hos[i]);
		choose(i, cnt + 1);
		res.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				hos.push_back(make_pair(i, j));
		}
	}
	choose(-1, 0);
	cout << min_val;
}
