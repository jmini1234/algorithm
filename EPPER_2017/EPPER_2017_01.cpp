#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

// 1부터 n까지 2와 3의 배수만 출력 
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			cout << i << " ";
		}
	}
}
