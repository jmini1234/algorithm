#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;
int n, m;
int bott[100001];
int topt[100001];
int res[500001];
int id1 = 0;
int id2 = 0;

int bot_search_idx(int i, int start, int end, int arr[]) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] < i) {
			start = mid + 1;
		}
		// 크거나 같을 때는 계속 줄이기
		else {
			end = mid;
		}
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cin >> bott[id1++];
		}
		else {
			cin >> topt[id2++];
		}
	}
	sort(bott, bott + id1);
	sort(topt, topt + id2);
	


	for (int i = 1; i <= m; i++) {
		int c1 = id1 - bot_search_idx(i, 0, id1, bott);
		int c2 = id2 - bot_search_idx(m - i + 1, 0, id2, topt);
		res[i-1] = c1 + c2;
	}

	sort(res, res + m);
	int min_val = res[0];
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		if (res[i] == min_val) {
			cnt++;
		}
		else
			break;
	}

	cout << min_val << ' '<< cnt;

}
