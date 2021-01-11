#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
int n;
vector<int>v;
int res = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int low = 0;
	int high = v[v.size() - 1];

	while (low <= high) {
		// 인덱스 후보 (k)
		int mid = (low + high) / 2;
		int lower = 0;
		int higher = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] <= mid)
				lower++;
			if (v[i] >= mid)
				higher++;
		}

		if (higher >= mid) {
			res = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << res;
}
