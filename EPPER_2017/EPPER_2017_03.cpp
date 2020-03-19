#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;


int main()
{
	int n;
	cin >> n;
	
	string name[50];

	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
	}

	for (int i = 0; i < n; i++) {
		cout << "Hello," << " "<< name[i] << "!" << endl;
	}

}
