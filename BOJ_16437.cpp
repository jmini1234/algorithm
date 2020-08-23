#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define NMAX 123456
int n;
long long num[NMAX + 1];
vector<vector<int> > child(NMAX + 1); // 이차원 배열로 각 부모 노드에 연결된 자식 노드들

// 단말노드부터 위에서 올라가야한다. 
long long postorder(int idx) {
	if (!child[idx].empty()) {
		for (auto &k : child[idx])
			num[idx] += postorder(k);
		return max(num[idx], (long long)0);
	}
	else
		return max(num[idx], (long long)0);
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		char c;
		int parent;
		cin >> c >> num[i] >> parent;
		if (c == 'W')
			num[i] *= -1; // 늑대의 수이기 때문에
		child[parent].push_back(i);
	}

	cout << postorder(1);
	
}
