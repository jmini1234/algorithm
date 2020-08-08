#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <stdlib.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		bool r = false;
		deque <int> dq;
		// R이 나오면 계속 숫자 위치가 달라진다.
		// 따라서 앞, 뒤에서 숫자를 삭제할 수 있다. 
		// deque사용하기 
		string cmd;
		int num;
		string str;
		cin >> cmd >> num >> str;
		//[1,2,3,4] 라는 string 인풋에서 
		// 숫자를 빼야한다. 
		// [1,2,3,4,]로 만든다. 
		str[str.size() - 1] = ',';
		int pos = 1;
		while (1) {
			int pos2 = str.find(',', pos);
			// 더이상 찾지 못하거나 같은 idx를 반환할 때 
			if (pos2 == string::npos || pos2 == pos)
				break;
			// 찾은 이후부터 찾아라
			dq.push_back(stoi(str.substr(pos, pos2 - pos)));
			pos = pos2 + 1;
		}
		for (int i = 0; i < cmd.size(); i++) {
			char ch = cmd[i];
			if (ch == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					goto tcbreak;
				}
				else {
					if (r)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
			else {
				r = !r;
			}
		}
		cout << '[';
		while (!dq.empty()) {
			if (r) {
				cout << dq.back();
				dq.pop_back();
			}
			else {
				cout << dq.front();
				dq.pop_front();
			}
			if (!dq.empty())
				cout << ',';
		}
		cout << "]\n";
	// goto break 문 ! 
	tcbreak:;
	}
}
