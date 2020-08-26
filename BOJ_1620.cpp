#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string arr[100001];

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	// 문자열을 통해 idx를 출력해야하기 때문에 
	// map 사용, key : string, value : int
	map <string, int> map1;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		// emplace는 make_pair와 비슷하게 묶어서 넣어준다.
		map1.emplace(name, i);
		arr[i] = name;
	}
	while (m--) {
		string name;
		cin >> name;
		if (name[0] >= '0' && name[0] <= '9')
			cout << arr[stoi(name)] << '\n';
		else
			cout << map1[name] << '\n';
	}
}
