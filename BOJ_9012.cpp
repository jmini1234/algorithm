#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int n;

bool isRight(string str) {

		stack <char> st;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				st.push('(');
			}
			else {
				if (st.empty())
				{
					return false;
				}
				else {
					st.pop();
				}
			}
		}
		if (!st.empty())
			return false;
		else
			return true;
	

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (isRight(str))
			cout << "YES" <<endl;
		else
			cout << "NO"<< endl;
	}

}
