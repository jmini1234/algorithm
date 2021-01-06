#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int n;
vector<int> v;
vector<int> gaps;
int res = INT_MAX;
int cnt = 0;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int gap = INT_MAX;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n - 1; i++) {
		gaps.push_back(v[i + 1] - v[i]);
	}

	for (int i = 0; i < gaps.size()-1; i++) {
		res = min(gcd(gaps[i+1], gaps[i]), res);
	}

	for (int i = 0; i < n - 1; i++) {
		cnt+=((v[i + 1] - v[i])/res - 1);
	}
	cout << cnt;
}
