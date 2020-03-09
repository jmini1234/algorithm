#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;
int N;
int *arr = (int *)malloc(sizeof(int)*N);
int *dp = (int *)malloc(sizeof(int)*N);
int res = 0;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int cont = 0;

	//동적계획법
	//최대값을 계속 저장해놓고 해당 값을 넣었을때 최대값 비교하기 
	//세개일때 세개로 더할 수 있는 조합 중 가장 큰 값을 찾아서 배열에 계속해서 저장하기 


	if (N == 1) {
		cout << arr[0];
		return 0;
	}
	else if (N ==2) {
		cout << arr[0]+arr[1];
		return 0;
	}

	else {
		dp[0] = arr[0];
		dp[1] = arr[0] + arr[1];
		dp[2] = max(dp[0] + arr[2], arr[1] + arr[2]);

		sum = max(dp[0], max(dp[1], dp[2]));

		for (int i = 3; i < N; i++) {
			dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]));
			if (sum < dp[i]) {
				sum = dp[i];
			}
		}
	}

	cout << sum;


}

