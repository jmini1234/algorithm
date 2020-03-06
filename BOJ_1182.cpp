#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <deque>

using namespace std;
int N, S;
int *arr = (int *)malloc(sizeof(int)*N);
int res = 0;

void dfs(int sum, int index) {
	if (index == N) {
		if (sum == S) {
			res++;
		}
		return;
	}

	dfs(sum + arr[index], index + 1);
	dfs(sum , index + 1);

}

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);

	if (S == 0)
		res--;

	cout << res;
}


/*
중요한 점 : 모든 부분 집합의 합을 구해서 비교해야함. 
모두 할 수 없으니까 하나의 원소가 있을 때와 없을 때를 나눠서 구해야함 
재귀함수 사용하기 .. .!! 
*/
