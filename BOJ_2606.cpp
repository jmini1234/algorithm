#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int cnt;
bool visited[105] = { false, };
bool check[105][105] = { false, };

void dfs(int start) {
	//cout << start << endl;
	visited[start] = true;
	for (int i = 1; i <= n; i++) {
		if (check[start][i] == true && visited[i] == false) {
			dfs(i);
		}
	}
}

int main(void) {
	cin >> n >> cnt;

	while(cnt--) {
		int n1, n2;
		cin >> n1 >> n2;
		check[n1][n2] = true;
		check[n2][n1] = true;
	}

	dfs(1);

	int res = 0;
	// 1번 컴퓨터 (idx=0) 제외
	for (int i = 2; i <= n; i++) {
		if (visited[i] == true)
			res++;
	}
	cout << res;


}
