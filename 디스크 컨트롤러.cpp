#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 최소힙 정의
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
queue <pair<int,int>> q;
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	// 들어온 순으로 정렬 후 queue에 넣기
	sort(jobs.begin(), jobs.end());
	for (int i = 0; i<jobs.size(); i++) {
		q.push(make_pair(jobs[i][0], jobs[i][1]));
	}
	int end_time = 0;
	int sum_val = 0;

	while (1) {
		if (q.empty() && pq.empty())
			break;
		// 이번 프로세스 끝내면 다시 시작하는 시간
		pair<int, int> cur = q.front();
		int start = cur.first;
		int total = cur.second;
		// 이 때 끝날거야
		end_time = 0;
		end_time += (start + total);
		// 현재 프로세스 반환 시간 (끝난시간 - 처음 들어온 시간)
		sum_val += (end_time - start);
		q.pop();
		// 끝나는 시간보다 일찍 시작하는 값은 모두 넣기
		while (!q.empty() && q.front().first <= end_time) {
			// 대신 걸리는 시간 순으로 정렬해야하기 때문에 순서 바꿔서 넣기
			// 걸리는 시간, 시작 시간
			pq.push(make_pair(q.front().second, q.front().first));
			q.pop();
		}
		while (!pq.empty()) {
			pair<int, int> cur = pq.top();
			int start = cur.second;
			int total = cur.first;
			end_time += total;
			sum_val += (end_time - start);
			pq.pop();
			// 큐에 있는 값 중 끝나는 시간보다 일찍 시작하는 값은 모두 넣기
			while (!q.empty() && q.front().first <= end_time) {
				// 대신 걸리는 시간 순으로 정렬해야하기 때문에 순서 바꿔서 넣기
				pq.push(make_pair(q.front().second, q.front().first));
				q.pop();
			}
		}
	}

	answer = sum_val / jobs.size();
	return answer;
}
