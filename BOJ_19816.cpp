#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n,m;
unordered_map <int,int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n; cin >> n;
		if (s.find(n) == s.end())
			s.insert(make_pair(n, 1));
		else
			s[n]+=1;
	}

	cin >> m;
	while (m--) {
		int num; cin >> num;
		cout << s[num] << ' ';
	}
}
