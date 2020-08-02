#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N, C;
int arr[200001];

int cal_max(int left, int right) {
	int ans;
	// 등호 들어가야하는 이유 ? 
	while (left <= right) {
		int cnt = 1;
		// 중간 값으로 일단 구해본다.
		int gap = (left + right) / 2;
		int house = arr[0];
		for (int i = 1; i < N; i++) {
			if (arr[i] - house >= gap) {
				cnt++;
				house = arr[i];
			}
		}
		// 사이의 거리가 너무 좁다는 뜻, 더 넓게
		if (cnt >= C) {
			left = gap + 1;
			ans = gap;
		}
		else if (cnt < C) {
			// -1로 해야하는 이유 ?
			right = gap-1;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		int val;
		scanf("%d", &val);
		arr[i]=val;
	}

	sort(arr, arr + N);

	// left와 right에 넣어야할 값은 
	// 간격이다. 
	// 가장 작은 간격 -> 1
	// 가장 큰 간격 -> 정렬했을 때의 간격
	printf("%d",cal_max(1, arr[N-1]-arr[0]));

}
