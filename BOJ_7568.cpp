#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
vector<pair<int,int>>v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int kg, cm;
		cin >> kg >> cm;
		v.push_back(make_pair(kg, cm));
	}

	for (int i = 0; i < n; i++) {
		int cur_kg = v[i].first;
		int cur_cm = v[i].second;
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				//cout << cur_kg << ' ' << cur_cm << endl;
				if (cur_kg < v[j].first && cur_cm < v[j].second) {
					cnt++;
				}
			}
		}
		cout << cnt << ' ';
	}

}
