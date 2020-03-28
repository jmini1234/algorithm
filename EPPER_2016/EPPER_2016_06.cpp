#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>
#include <ctype.h>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int arr1[20];
	int arr2[20];

	if (s1.size() != s2.size()) {
		cout << "NO";
		return 0;
	}
	else {
		for (int i = 0; i < s1.size(); i++) {
			arr1[i] = tolower(s1[i]);
			arr2[i] = tolower(s2[i]);
		}

		sort(arr1, arr1 + s1.size());
		sort(arr2, arr2 + s2.size());

		for (int i = 0; i < s1.size(); i++) {
			if (arr1[i] != arr2[i])
			{
				cout << "NO";
				return 0;
			}
		}

		cout << "YES";
	}

}
