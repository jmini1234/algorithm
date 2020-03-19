#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int res = 0;

// 숫자에 3,6,9가 포함되어있는지 뒷자리부터 확인 
// 만약 있으면 바로 res 더하고 끝내기 

void isClap(int n) {
	while (n != 0) {
		int tmp = n % 10;
		if (tmp == 3 || tmp == 6 || tmp == 9) {
			res++;
			return;
		}
		n = n / 10;
	}
}

int main()
{
	int S, E;
	cin >> S >> E;

	for (int i = S; i <= E; i++)
	{
		isClap(i);
	}

	cout << res ;
}
