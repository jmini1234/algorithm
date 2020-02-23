#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <deque>

using namespace std;

int main() {

	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;

	deque<char> dq;

	for (int i = 0; i < n; i++) {
		while (k>0 && !dq.empty() && s[i] > dq.back()) {
			dq.pop_back();
			k--;
		}
		dq.push_back(s[i]);
	}

	for (int i = 0; i < dq.size() - k; i++) {
		cout << dq[i];
	}

}
