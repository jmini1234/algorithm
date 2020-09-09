#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long N;
	int B;
	cin >> N >> B;
	char ch[26];
	for (int i = 0; i < 26; i++) {
		ch[i] = 'A' + i;
	}
	vector<int>v;
	while (N != 0) {
		int tmp = N%B;
		v.push_back(tmp);
		N = N / B;
	}
	for (int i = v.size()-1; i>=0; i--) {
		int tmp = v[i];
		if (tmp < 10)
			cout << tmp;
		else
			cout << ch[tmp - 10];
	}
}
