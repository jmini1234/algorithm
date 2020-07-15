#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>
#include <vector>

using namespace std;

int arr[10] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		arr[i]=i+1;
	do{
		for (int i = 0; i < n; i++) cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(arr, arr + n));
}
