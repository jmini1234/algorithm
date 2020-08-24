#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector <vector <int>> graph(51);
int check[51] = { 0, };

void dfs(int idx) {
	check[idx] = 1;
	for (auto &k : graph[idx]) {
		dfs(k);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int parent;
		scanf("%d", &parent);
		if(parent!=-1)
			graph[parent].push_back(i);
	}
	int out;
	scanf("%d", &out);

	dfs(out);

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			int child = 0;
			for (auto &k : graph[i]) {
				if (!check[k])
					child++;
			}
			//cout << i << ' ' << child << endl;
			if (child == 0)
				cnt++;
		}
	}

	printf("%d", cnt);

}
