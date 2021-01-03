#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string str; cin >> str;
		list<char> li;
		auto iter = li.begin();
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if (ch == '<') {
				if (iter != li.begin()) iter--;
			}
			else if (ch == '>') {
				if (iter != li.end()) iter++;
			}
			else if (ch == '-') {
				if(iter!=li.begin()) iter = li.erase(--iter);
			}
			else
				li.insert(iter, ch);
		}
		for (auto &k : li)
			cout << k;
		cout << '\n';
	}
}
