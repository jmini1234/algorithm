#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;


int seperSum(int i) {
	int sum = 0;

	while (i != 0) {
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main() {
	
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		if ((seperSum(i) + i) == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
	
}

