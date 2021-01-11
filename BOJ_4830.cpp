#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
vector<bool>visited;
vector<bool>cycle;
vector<int> arr[505];
int idx = 0;
bool flag;

void dfs(int idx, int before) {
	// 연결되어 있는 것들 
	// 1-> 2 -> 3 -> 4 -> 1
	for (int i = 0; i < arr[idx].size(); i++) {
		if (arr[idx][i] == before)
			continue;
		if (!visited[arr[idx][i]]) {
			visited[arr[idx][i]] = true;
			dfs(arr[idx][i],idx);
		}
		else {
			// cycle임
			flag = true;
			return;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int cnt = 0;
		int v, e;
		cin >> v >> e;
		if (v == 0 && e == 0)
			return 0;

		idx++;

		visited = vector<bool>(v+1, false);
		cycle = vector<bool>(v + 1, false);

		for (int i = 1; i <= v; i++)
			arr[i].clear();

		for (int i = 0; i < e; i++) {
			int start, end; cin >> start >> end;
			arr[start].push_back(end);
			arr[end].push_back(start);
		}

		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				// 아직 시도 안한 시작점에 대해서
				flag = false;
				visited[i] = true;
				dfs(i,0);
				// 트리일때
				if (!flag)
					cnt++;
			}
		}

		if (cnt == 0) {
			cout << "Case " << idx << ": No trees.\n";
		}
		else if (cnt == 1) {
			cout << "Case " << idx << ": There is one tree.\n";
		}
		else {
			cout << "Case " << idx << ": A forest of " << cnt << " trees.\n";
		}
	}
}
