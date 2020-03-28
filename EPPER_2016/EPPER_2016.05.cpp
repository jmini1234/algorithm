#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int main()
{

	string pwd;
	cin >> pwd;
	string input;
	cin >> input;

	// c++에서는 string find함수가 index를 반환하기 때문에 
	// 없는 경우에는 매우 큰 수인 string::npos를 반환
	if (input.find(pwd)==string::npos)
		cout << "실패";
	else
		cout << "성공";


}
