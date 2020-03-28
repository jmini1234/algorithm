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

	int arr[100];

	int i = 0;

	while (true) {
		if (n == 0)
			break;
		else {
			arr[i] = n % 2;
			n /= 2;
			i++;
		}
	}

	int res = 0;

	for (int j = 0; j < i; j++) {
		if (arr[j] == 1)
			res++;
	}

	cout << res;

}
