#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
int pre[1001];
int in[1001];

void post(int start, int end, int root) {
	//cout << start << ' ' << end << ' ' << pre[root] << endl;
	for (int i = start; i < end; i++) {
		if (pre[root] == in[i]) {
			post(start, i, root+1);
			post(i+1, end, root+i-start+1);
			cout << pre[root] << ' ';
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			scanf("%d", &pre[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &in[i]);
		}

		post(0, n, 0);
		cout << endl;
	}
}
