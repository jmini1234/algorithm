#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <deque>

using namespace std;
int N;
int *arr = (int *)malloc(sizeof(int)*N);
int res = 0;

// 최소가 되는 규칙이 있음 & 재귀함수 사용 
int isPalindrome(int start,int end) {
	// 모든 인덱스 탐색 
	if (start > end)
		return res;
	// palindrome이면 수정하지 않고 하나씩 앞으로
	else if (arr[start] == arr[end])
		isPalindrome(start + 1, end - 1);
	else {
		// 작은 값을 두개 더해서 배열 수정한다.
		if (arr[start] < arr[end]) {
			arr[start + 1] = arr[start] + arr[start + 1];
			res++;
			isPalindrome(start + 1, end);
		}
		else {
			arr[end-1] = arr[end] + arr[end - 1];
			res++;
			isPalindrome(start, end - 1);
		}
	}
}

int main() {

	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start, end;
	start = 0;
	end = N - 1;

	cout << isPalindrome(start, end);


}

