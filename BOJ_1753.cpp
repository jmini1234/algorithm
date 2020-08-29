#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <limits.h>

using namespace std;

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> my_pq;
vector <pair<int, int>> adj[20010];
int dist[20010];

int main() {
	int v, e;
	int start;
	cin >> v >> e >> start;
	// 간선의 크기 만큼 adj 저장 
	// 벡터의 각 배열에 pair 가 저장되어있기 때문에 아래와 같이 크기 설정
	// 일반은 vector<int> a(100); 이다.

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	// limits.h 라이브러리에 정의되어 있음
	for (int i = 1; i <= v; i++) dist[i] = INT_MAX;

	// 가중치로 정렬되어야하기 때문에 먼저 쓰기
	my_pq.push(make_pair(0,start));
	dist[start] = 0;

	while (!my_pq.empty()) {
		// 가중치가 가장 작은 점의 가중치
		int cur_dist = my_pq.top().first;
		// 가중치가 가장 작은 점
		int cur = my_pq.top().second;
		my_pq.pop();
		// 현재 저장된 가중치보다 크면 계산할 필요 없음
		// 더 멀리 돌아온 점
		if (dist[cur] < cur_dist)
			continue;
		
		// 가중치가 가장 작은 점과 연결되어 있는 점
		for (auto &k : adj[cur]) {
			int next = k.first;
			int next_dist = k.second;
			// 가중치가 가장 작은 점을 통해 총 가중치가 더 작은 점이 있으면
			if (dist[next] > cur_dist + next_dist) {
				dist[next] = cur_dist + next_dist;
				// 갱신 후 우선순위 큐에 삽입
				my_pq.push(make_pair(next_dist + cur_dist, next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}
