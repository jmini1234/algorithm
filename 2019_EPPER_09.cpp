#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <deque>

using namespace std;
int N;
int *arr = (int *)malloc(sizeof(int)*N);
int res = 0;

int main() {

	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int cont = 0;

	//동적계획법
	//최대값을 계속 저장해놓고 해당 값을 넣었을때 최대값 비교하기 

	for (int i = 1; i < N; i++) {
		if (cont >= 2) {
			if (arr[i] > arr[i-2]) {
				sum -= arr[i - 2];
				sum += arr[i];
				cont = 2;
			}
			else {
				cont = 0;
			}
		}
		else {
			sum += arr[i];
			cont++;
		}
	}

	cout << sum;


}

