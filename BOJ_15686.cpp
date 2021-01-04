#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int n, m;
int arr[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chick;
vector<pair<int, int>>tmp;
vector<bool>flag(51, false);

int res = INT_MAX;

// 전체 치킨 집 중 m 개 고르기 
void removeChick(int idx) {
	if (tmp.size() == m) {
		int tmpdist = 0;
		// tmp에 저장된 것과 집의 치킨 거리 구하기
		for (int i = 0; i < house.size(); i++) {
			int tmpchickdist = INT_MAX;
			int hx = house[i].first; int hy = house[i].second;
			for (int j = 0; j < tmp.size(); j++) {
				int tx = tmp[j].first; int ty = tmp[j].second;
				tmpchickdist = min(tmpchickdist, abs(hx - tx) + abs(hy - ty));
			}
			tmpdist += tmpchickdist;
		}
		res = min(res, tmpdist);
		return;
	}
	for (int i = idx; i < chick.size(); i++) {
		if (!flag[i]) {
			tmp.push_back(chick[i]);
			flag[i] = true;
			removeChick(i + 1);
			flag[i] = false;
			tmp.pop_back();
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			// 집
			if (arr[i][j] == 1) house.push_back(make_pair(i, j));
			// 치킨
			else if (arr[i][j] == 2) chick.push_back(make_pair(i, j));
		}
	}
	removeChick(0);
	cout << res;

}
