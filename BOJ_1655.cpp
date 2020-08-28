#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <functional> // greater사용하기 위해

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;

	int n;
	cin >> n;
	// 지금까지 말한 수 중에서 중간값을 말해야하기 때문에
	// 수가 들어올 때마다 정렬 -> 우선순위 큐, 힙 사용

	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		int min_size = min_heap.size();
		int max_size = max_heap.size();

		// 최대힙 , 중간값, 최소힙
		// 중간값은 최대힙의 루트값
		if (min_size == max_size) {
			max_heap.push(val);
		}
		else {
			min_heap.push(val);
		}
		if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
			int min_val = min_heap.top();
			int max_val = max_heap.top();
			min_heap.pop();
			max_heap.pop();
			min_heap.push(max_val);
			max_heap.push(min_val);
		}
		cout << max_heap.top() << '\n';
	}
}
