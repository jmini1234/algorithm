#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector <vector <int>> graph(100001);
long long score[100001] = { 0, };

// preorder 방식을 사용해야 root 노드도 점수가 더해진다. 
void dfs(int idx) {
	for (auto &k : graph[idx]) {
		score[k] += score[idx];
		dfs(k);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int parent;
		cin >> parent;
		if (parent != -1)
			graph[parent].push_back(i);
	}
	while (m--) {
		int node, sc;
		cin >> node >> sc;
		score[node] += sc;
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		printf("%d ", score[i]);

}
