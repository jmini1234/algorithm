#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int main()
{
	int m;
	cin >> m;
	char arr[20];
	stack <int> st;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		char val = arr[i];
		if (val>='1' && val <= '9') {
			st.push(val - '0');
		}
		else {
			int n2 = st.top();
			st.pop();
			int n1 = st.top();
			st.pop();
			int res;

			if (val == '+') {
				res = n1 + n2;
			}
			else if (val == '-') {
				res = n1 - n2;
			}
			else if (val == '/') {
				res = n1 / n2;
			}
			else if (val == '*') {
				res = n1*n2;
			}
			st.push(res);
		}
	}

	cout << st.top();



}
