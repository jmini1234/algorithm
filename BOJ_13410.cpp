#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;

int N, K;

int reserve(int val) {
	// 한자리 수이면 pass
	if (val > 0 && val < 10)
		return val;
	// 두자리 이상이면 
	else {
		int sum = 0;
		int temp_val[100] = { 0, };
		int i = 0;
		while (val != 0) {
			// 자리수를 모두 temp_val 배열에 저장
			temp_val[i] = val % 10;
			val /= 10;
			i++;
		}
		// i는 자리수
		int tmp = i-1;
		for (int j = 0; j < i; j++) {
			sum += pow(10, tmp)*temp_val[j];
			tmp--;
		}
		return sum;
	}
}

int main() {
	cin >> N >> K;
	int gugu[1001] = { 0, };
	for (int i = 1; i <= K; i++) {
		int tmp = N*i;
		gugu[i] = reserve(tmp);
	}

	sort(gugu, gugu + K + 1);

	cout << gugu[K];
}

