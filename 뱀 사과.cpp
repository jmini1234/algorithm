#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, k;
int arr[101][101] = { 0, };
// R D L U
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector <pair<int, int>> q;
int mapper[4];
int res = 0;

bool IsTwisted(pair<int,int> newHead) {
	for (int i = 0; i < q.size(); i++) {
		// 한개만 겹쳐도 바로 true 반환
		if (newHead == q[i])
			return true;
	}
	return false;
}

bool MoveSnake(int nx, int ny) {
	if (arr[nx][ny] == 1) {
		arr[nx][ny] = 0;
		if (IsTwisted(make_pair(nx,ny))==false)
			q.insert(q.begin(),make_pair(nx, ny));
		else
			return false;
	}
	else {
		q.pop_back();
		if (IsTwisted(make_pair(nx,ny))==false)
			q.insert(q.begin(), make_pair(nx, ny));
		else
			return false;
	}
	return true;
}

bool Move(int direction, int distance) {
	while (distance--) {
		res++;
		int h_x = q.front().first + dx[direction];
		int h_y = q.front().second + dy[direction];
		// 한칸 이동했을 때 변화하는 머리
		if (h_x > n || h_x < 1 || h_y > n || h_y < 1)
			return false;
		if (MoveSnake(h_x, h_y) == false)
			return false;
	}
	return true;
}

int main() {
	mapper['R'] = 0;
	mapper['D'] = 1;
	mapper['L'] = 2;
	mapper['U'] = 3;
	cin >> n >> m >> k;
	while (m--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	// 1,1 부터 시작
	// 꼬리와 몸통의 위치 정보를 queue에 넣는다.
	q.push_back(make_pair(1, 1));

	while (k--) {
		char direction;
		int distance;
		cin >> direction >> distance;
		if (Move(mapper[direction], distance) == false)
			break;
	}
	
	cout << res;

}
