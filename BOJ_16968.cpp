#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>
#include <vector>

using namespace std;

int main() {
	string str;
	int sum;
	cin >> str;
	if (str[0] == 'd') {
		sum = 10;
	}
	else {
		sum = 26;
	}
	for (int i = 1; i < str.size(); i++) {
		// 이전 문자와 같을 때
		if (str[i - 1] == str[i]) {
			// 문자일 때
			if (str[i] == 'c') {
				sum *= 25;
			}
			// 숫자일 때
			else {
				sum *= 9;
			}
		}
		else {
			// 문자일 때
			if (str[i] == 'c') {
				sum *= 26;
			}
			// 숫자일 때
			else {
				sum *= 10;
			}
		}
	}
	cout << sum;

}

