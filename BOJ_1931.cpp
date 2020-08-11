#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int,int>>arr;

bool cmp(pair <int, int> a, pair <int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void) {
	int N;
	cin >> N;
	while(N--) {
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end(), cmp);

	int res = 1;
	int current = arr[0].second;
	
	for (int i = 1; i < arr.size(); i++) {
		int start = arr[i].first;
		if (start >= current) {
			res++;
			current = arr[i].second;
		}
	}
	
	
	cout << res;
}
