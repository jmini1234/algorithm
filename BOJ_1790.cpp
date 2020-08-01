#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include <math.h>

using namespace std;
int n, m;

long long calNumber(int num) {
	// 몇자리인지를 구하기 위해서 
	// num을 log10으로 계산해서 자리 수 계산
	int k = int(log10(num));
	long long sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += (i*(pow(10, i) - pow(10, i - 1)));
	}
	sum += (k+1)*((long long) num - pow(10, k) + 1);
	return sum;
}

int binary_search(int left,int right) {
	while (left < right) {
		// mid 까지의 숫자의 개수가 m개 인지 확인
		// 즉 1부터 n 까지가 calNumber개 
		// m 번째 숫자가 어떤 수까지의 개수인지 확인하기 위해
		// 이분 탐색을 사용해서 찾아낸다.
		int mid = (left + right) / 2;
		if (calNumber(mid) < m)
			left = mid + 1;
		else
			right = mid;
	}
	// m번째 숫자가 1부터 right까지이다.
	return right;
}

int main() {
	scanf("%d %d", &n, &m);
	// 1부터 num까지의 수를 합친 것이다. 
	int num = binary_search(1, n);
	// num까지의 개수 
	long long size = calNumber(num);
	if (calNumber(n) < m)
		printf("%d", -1);
	else {
		string s = to_string(num);
		printf("%c", s[s.size() - (size - m) - 1]);
	}
}
