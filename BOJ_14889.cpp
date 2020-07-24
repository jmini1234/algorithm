#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
int arr[21][21] = { 0, };
int n;
int visited[21] = { false, };
int min_val = 10000000;

void cal(int visited[]) {
	vector <int> team_link;
	vector <int> team_start;

	for (int i = 1; i <= n; i++) {
		if (visited[i] == true)
		{
			team_link.push_back(i);
		}
		else {
			team_start.push_back(i);
		}
	}
	int start_sum=0, link_sum = 0;
	// 스타트와 링크 팀 능력 차이 구하기
	// 각 배열에서 두명씩 뽑아야 하니까 이중 for 문 사용해서 계산하기
	for (int i = 0; i < team_start.size(); i++) {
		for (int j = i + 1; j < team_start.size(); j++) {
			int start_x = team_start[i], start_y = team_start[j];
			int link_x = team_link[i], link_y = team_link[j];
			start_sum += arr[start_x][start_y] + arr[start_y][start_x];
			link_sum += arr[link_x][link_y] + arr[link_y][link_x];
		}
	}
  // 두 점수의 차이와 이전 값을 비교해서 min_val 갱신하기
	min_val = min(min_val, abs(start_sum - link_sum));
	return ;
}

// seq에 답을 계속해서 저장 한 후 출력
// 출력이 여러개이므로 param 가 하나 더 필요하다.
void dfs(int idx, int cnt) {
  // 두 팀으로 나누어졌으면 선택된 정보를 cal함수에 보낸다.
	if (cnt == n / 2) {
		cal(visited);
		return;
	}
	// idx 보다 큰 얘들 중에서 선택한다. !!!!! 완전탐색이기 때문에 반복문 필수 !!!!!! 
	for (int i = idx+1; i <= n; i++) {
		// 해당 idx가 선택되지 않은 수라면
		if (visited[i] == false) {
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false;
		}
	}


}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(1, 0);
	cout << min_val;
}
