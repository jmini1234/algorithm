#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;

int arr[100000] = { 0, };


int binarySearch(int low, int high, int num)
{
	if (low > high)
		return 0;
	else
	{
		int mid = (low + high) / 2;
		if (arr[mid] == num)
			return 1;
		else if (arr[mid] > num)
			return binarySearch(low, mid - 1, num);
		else
			return binarySearch(mid + 1, high, num);
	}

}

int main()
{
	int N;
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cin >> N;
	for (int i = 0; i < N; i++) {
		int idx;
		cin >> idx;
		arr[i] = idx;
	}
	sort(arr, arr + N);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		cout << binarySearch(0, N - 1, num) << "\n";
	}
}
