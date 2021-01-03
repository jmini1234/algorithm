#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int t;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int n, target;
		cin >> n >> target;
		int res = 0;
		vector<int> imp;
		queue<pair<int,int>> q;
		// idx와 중요도 queue에 저장
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			imp.push_back(num);
			q.push(make_pair(i,num));
		}
		sort(imp.begin(), imp.end(),cmp);
		while (1) {
			// 현재 가장 큰 중요도 
			int max = imp[0];
			imp.erase(imp.begin());
			// 가장 큰 중요도가 나올 때까지
			while(q.front().second != max) {
				pair<int, int> p = q.front(); q.pop();
				q.push(p);
			}
			res++;
			// 원하는 인덱스일 경우
			if (q.front().first == target)
				break;
			else
				q.pop();
		}
		cout << res << '\n';
	}

}
