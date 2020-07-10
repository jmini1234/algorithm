#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;

	for (int i = 1; i <= N; i++) {
		if (i > 0 && i < 100)
			count = i;
		if (i == 1000)
			break; 
		else {
			int arr[3] = { 0, };
			int k = 0;
			int temp = i;
			while (temp != 0) {
				arr[k] = temp % 10;
				temp = temp / 10;
				k++;
			}
			if ((arr[0] - arr[1]) == (arr[1] - arr[2]))
				count++;
		}
	}
	cout << count;
}

