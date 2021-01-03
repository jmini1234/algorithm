#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
int n;
struct dot {
	int x;
	int y;
	dot(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<dot> Dot;


bool cmp(dot d1, dot d2) {
	if (d1.y == d2.y)
		return d1.x < d2.x;
	else
		return d1.y < d2.y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		Dot.push_back(dot(x, y));
	}

	sort(Dot.begin(), Dot.end(), cmp);

	for (auto &k : Dot)
		cout << k.x << ' ' << k.y << '\n';
}
