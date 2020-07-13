#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;


int main() {

	int i = 0;
	int cnt = 0;
	int arr[20] = { 0, };

	while (1) {
		int val;
		cin >> val;
		if (val == 0) {
			for (int j = 0; j < i; j++) {
				int tmp = arr[j];
				for (int k = j+1; k < i; k++) {
					if (arr[k] == tmp * 2 || arr[k] *2 == arr[j]) {
						cnt++;
					}
				}
			}
			cout << cnt << endl;
			i = 0;
			cnt = 0;
		}
		else if (val == -1) {
			return 0;
		}
		else {
			arr[i++] = val;
		}
	}

}

