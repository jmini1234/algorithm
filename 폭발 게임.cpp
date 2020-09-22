#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <deque>

using namespace std;

int n, m;
int arr[101];

// 인수로 배열과, 해당 배열의 크기를 입력 받음
// 벡터로 했으면 .size() 쓰면 쉬울텐데
void cal(int arr[],int size) {
	// 변화가 있는지 판단
	bool flag = false;
	int start = 0;
	// m 개 이상의 반복되는 수가 있는지 모두 판단
	while (start<size) {
		int val = arr[start];
		int end = start;
		// 동일한 숫자가 몇 개 존재하는지 확인
		while (val == arr[end]) {
			end++;
		}
		// m개 이상이면
		if (end - start >= m) {
			// 값을 0으로 바꾼다.
			for (int i = start; i < end; i++)
				arr[i] = 0;
			// 변화했기 때문에 flag 바꿈
			flag = true;
		}
		// 그 다음에도 있을 수 있기 때문에 확인하기
		start = end;
	}

	int tmp[101];
	int idx = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0)
			// 0이 아닌, 즉 폭발되지 않은 값에대해서만 
			// 새로운 배열 tmp 만듦
			tmp[idx++] = arr[i];
	}
	// 변화했으면 갱신해서 맞춰보기
	if (flag)
		cal(tmp,idx);
	else {
		cout << idx << '\n';
		for (int i = 0; i < idx; i++)
			cout << tmp[i] << '\n';
		return;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cal(arr,n);
}
