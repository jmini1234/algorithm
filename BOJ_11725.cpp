#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector <vector <int>> graph(100001);
int parent[100001] = { 0, };

void dfs(int idx) {
	for (auto &k : graph[idx]) {
		if (parent[k]==0) {
			parent[k] = idx;
			dfs(k);
		}
	}
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", parent[i]);
	}

}
