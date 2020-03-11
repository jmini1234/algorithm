#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[21] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 평균이 언제 가장 큰지 생각해보기 
	// 모든 경우 할 필요 없고 작은 수부터 평균 구하면 가장 커진다(평균이 확 깎이는 경우가 없음/ 계속 누적됨)
	// float 나눌때 2.0으로 하는거 잊지 않기 ...
	
	sort(arr, arr + n);

	if (n == 1)
		printf("%.06f", arr[1]);
	else {
		float avg = (arr[0] + arr[1]) / 2.0;
		for (int i = 2; i < n; i++) {
			avg = (avg + arr[i]) / 2.0;
			cout << arr[i] << " ";
		}
		printf("%.06f", avg);

	}




}
