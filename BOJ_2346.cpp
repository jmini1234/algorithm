#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <deque>

using namespace std;
deque<pair<int,int>> dq;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		dq.push_back(make_pair(i,num));
	}

	while (!dq.empty()) {
		int num = dq.front().second;
		cout << dq.front().first << ' ';
		dq.pop_front();

		if(num<0){
			num*=-1;
			while (num--) {
				pair<int, int> tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
		else {
			num--;
			while (num--) {
				pair<int, int> tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}
	}


}
