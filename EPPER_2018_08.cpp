#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int main()
{
	string p;
	cin >> p;

	string secret;
	cin >> secret;

	int len = p.length();

	// 7의 배수가 아니면 뒤에 알파벳을 더해줌 
	if (len % 7 != 0) {
		for (int i = 0; i < (len-1) - 7; i++) {
			p += 'a' + i;
		}
	}

	// 7의 배수로 만든 후 몫을 구한다. 
	int len_aft = p.length();

	int iter = len_aft / 7;

	// 몫만큼 반복해서 출력
	for (int j = 0; j < iter; j++) {
		for (int i = 0; i < secret.length(); i++) {
			int idx = (secret[i] - '0');
			cout << p[(idx - 1)+ 7*j];
		}
	}



}
