#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	map <string, int> m;
	string str;
	int total = 0;

	while (getline(cin,str)) {
		// 이미 있을 때 
		if (m.find(str) != m.end())
			m[str]++;
		// 없을 때 
		else
			m.emplace(str, 1);
		total++;
	}

	// 소수점 넷째자리까지 표시
	cout.precision(4);
	cout << fixed;

	for (auto &k : m) {
		cout << k.first << ' ' << ((double) k.second / total) * 100 << '\n';
	}

}
