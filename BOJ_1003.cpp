#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int zero = 0;
int one = 0;
int t = 0;

vector<pair<int, int>> v(45);


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	// 초기화 
	v[0].first = 1;
	v[0].second = 0;
	v[1].first = 0;
	v[1].second = 1;
	while (t--) {
		int n; cin >> n;
		if (n != 0 && n != 1) {
			for (int i = 2; i <= n; i++) {
				v[i].first = v[i - 1].first + v[i - 2].first;
				v[i].second = v[i - 1].second + v[i - 2].second;
			}
		}
		cout << v[n].first << ' ' << v[n].second << '\n';
	}
}
