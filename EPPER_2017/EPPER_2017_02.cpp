#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;


int main()
{
	int m, d;
	cin >> m >> d;
	int day_count[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string day [7] = { "일요일","월요일","화요일","수요일","목요일","금요일","토요일" };
	// 1월 1일이 일요일 
	// 1월 2일은 월요일 => 더한 값은 1 => 1%7은 1 일요일
	// 4월 1일은 토요일 => 더한 값 31+28+31=90 => 90%7은 6 토요일 

	int sum = 0;
	for (int i = 0; i < m-1; i++) {
		sum += day_count[i];
	}
	sum += (d - 1);


	cout << day[sum % 7];


}
