#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int N, r, c;

int res = 0;

void solve(int size, int y, int x) {

	// 재귀가 끝날때 답이 맞는지 확인하는 곳 
	if (size == 2) {
		if (y == r && x == c) {
			cout << res << "\n";
			return;
		}
		res++;
		if (y == r && x + 1 == c) {
			cout << res << "\n";
			return;
		}
		res++;
		if (y + 1 == r && x == c) {
			cout << res << "\n";
			return;
		}
		res++;
		if (y + 1 == r && x + 1 == c) {
			cout << res << "\n";
			return;
		}
		res++;
		// 답이 아닐 때 꼭 return 해서 끝내줘야함 
		return;
	}


	solve(size / 2, y, x);
	solve(size / 2, y, x+size/2);
	solve(size / 2, y+size/2, x);
	solve(size / 2, y+size/2, x+size/2);


}

int main()
{

	cin >> N >> r >> c;


	solve(1<<N, 0, 0);

}
