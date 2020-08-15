#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;


// 11+4-5+4-3+5-3
// 55-42+5-4+45-7

// +와 -가 번갈아가면서 나온다. 
// 맨 처음 값이 + 이면 앞에서 두번째 수까지 더하고 뒤의 모든 값들 모두 빼줌
// - 이면 맨 앞 값만 더해주고 뒤에 모든 수는 빼줌

int main(void) {
	deque <int> st;
	string str;
	cin >> str;
	int res = 0;
	string tmp = "";
	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		char ch = str[i];
		if (ch == '+' || ch == '-' || ch == '\0') {
			if (minus)
				res -= stoi(tmp);
			else
				res += stoi(tmp);
			tmp = "";
			if (ch == '-')
				minus = true;
		}
		else
			tmp += ch;
	}

	cout << res;
}
