#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// 큐도 2차원 배열에 넣을 수 있음
// 회전하는 것 주로 dq나 q에 넣기
deque <int> dq[4];
int k;

bool visited[4] = { false, };

void move(int num, int dir) {
	// 이미 검사 끝냈다는 것을 표시
	// ex) 2에서 1로 갔는데 1은 다시 2를 검사할 수 없음
	visited[num] = true;
	// 양 옆 idx 검사 
	// 일단 계산하고 범위에 맞지 않으면 진행 x (굳이 case에 따라 다르게 진행하지 않아도 됨)
	// 현재 위치에 따라서 바꿀 것을 결정한다.
	int left = num - 1;
	int right = num + 1;
	if (left >= 0 && !visited[left] && (dq[left][2] != dq[num][6])) {
		move(left, dir*(-1));
	}
	if (right < 4 && !visited[right] && (dq[num][2] != dq[right][6])) {
		move(right, dir*(-1));
	}
	// 시계 방향
	if (dir == 1) {
		int e = dq[num].back();
		dq[num].push_front(e);
		dq[num].pop_back();
	}
	// 반시계 방향
	else {
		int f = dq[num].front();
		dq[num].push_back(f);
		dq[num].pop_front();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			dq[i].push_back(str[j]-'0');
		}
	}

	cin >> k;
	while (k--)
	{
		for (int i = 0; i < 4; i++)
			visited[i] = false;

		int num, dir;
		cin >> num >> dir;
		// idx 맞춰주기
		move(num-1, dir);
	}

	int total = 0;
	for (int i = 0; i < 4; i++) {
		if (dq[i][0] == 1)
			total += pow(2, i);
	}

	cout << total;


}
