#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>
#include <ctype.h>

using namespace std;

int main()
{

	string str;
	cin >> str;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - (i + 1)]) {
			cout << "NO";
			return 1;
		}
	}
	cout << "YES";

}
