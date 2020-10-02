#include <iostream>
#include <vector>

using namespace std;
int n;
int val[3] = { 4,5,6 };
vector<int> v;

bool IsEqual(int s1, int s2, int len) {
	for (int i = 0; i < len; i++) {
		if (v[s1 + i] != v[s2 + i])
			return false;
	}
	return true;
}

bool IsAvailable() {
	// 연속 부분 수열이 존재하는지 판단
	// 모든 길이의 부분 수열을 검토
	for (int i = 0; i < v.size(); i++) {
		int len = 1;
		while (1) {
			int start1 = i, end1 = i + len - 1;
			int start2 = end1+1, end2 = start2 + len - 1;
			if (end2 >= v.size())
				break;
			if (IsEqual(start1, start2, len))
				return false;
			len++;
		}
	}
	return true;
}

void choose(int cnt) {
	if (cnt == n) {
		for (auto &k : v)
			cout << k;
		exit(0);
	}
	for (int i = 0; i < 3; i++) {
		v.push_back(val[i]);
		if (IsAvailable())
			choose(cnt + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n;
	choose(0);
}
