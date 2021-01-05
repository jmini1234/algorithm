#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n, k;
bool flag[100001] = { false, };
int res = INT_MAX;
queue <pair<int, int>>q;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	// 가능한 모든 경우의 수를 진행
	q.push(make_pair(n, 0));
	flag[n] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == k) {
			res = min(res, cnt);
		}
		else {
			int tmp[3] = { cur + 1,cur - 1,2 * cur };
			for (int i = 0; i < 3; i++) {
				if (tmp[i] >= 0 && tmp[i] < 100001 && !flag[tmp[i]]) {
					flag[tmp[i]] = true;
					q.push(make_pair(tmp[i], cnt+1));
				}
			}
		}
	}

	cout << res;
}
