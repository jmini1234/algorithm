#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int n;
string str="";

bool IsGood(string str) {
	// 부분 수열 시작 인덱스
	for (int i = 0; i < str.size(); i++) {
		// 부분 수열 크기(최대는 문자열 전체의/2)
		for (int j = 1; j <= str.size() / 2; j++) {
			// 부분 수열 바로 다음에 크기가 동일한 부분 수열이 존재할 때 비교 진행
			if (i + 2 * j <= str.size()) {
				string s1= str.substr(i, j);
				string s2 = str.substr(i + j, j);
				if (s1 == s2)
					return false;
			}
		}
	}
	return true;
}

void dfs(string tmp) {
	if (tmp.size() == n) {
		cout << tmp;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		tmp += to_string(i);
		if (IsGood(tmp))
			dfs(tmp);
		tmp.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(str);
}
