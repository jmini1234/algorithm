#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int n;
int res = 0;

// 사용된 왼쪽 괄호 => open 오른쪽 괄호 => close
// 재귀 사용해서 문제의 조건 파악 

void getRes(int open, int close) {
	// 오른쪽 괄호가 다 사용되었을때 +1
	if (close == n)
		res++;
	// 왼쪽 괄호가 다 사용되었을때는 오른쪽 괄호밖에 사용하지 못한다
	else if (open == n) {
		getRes(open, close + 1);
	}
	// 괄호 사용 횟수가 같으면 왼쪽 괄호만 가능 
	else if (open == close) {
		getRes(open + 1, close);
	}
	// 오른쪽 괄호를 더 많이 사용했을때 둘 다 사용가능 
	// 왼쪽 괄호를 더 많이 사용한 경우는 계산 x 
	else if (open > close) {
		getRes(open + 1, close);
		getRes(open, close + 1);
	}
}

int main()
{
	cin >> n;

	getRes(0, 0);
	
	cout << res;


}
