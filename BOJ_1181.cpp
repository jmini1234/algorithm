#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// sort를 위한 세번째 함수는 2개의 값을 입력받는다. 

bool cmp(string a, string b) {
	int a_size = a.size();
	int b_size = b.size();
  // 일단 길이가 짧은 것 부터
	if(a_size!=b_size)
		return a.size() < b.size();
  // 아니면 사전순, string은 그냥 비교하면 사전순이 된다.
	return a < b;
}

int main() {
	int n;
	string str[20001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}


// c++의 sort 함수 쓰기 , 세번째 함수로 정렬할 수 있음 

	sort(str, str + n, cmp);

	for (int i = 0; i < n; i++) {
		if (str[i].compare(str[i+1])!=0) {
			cout << str[i] << "\n";
		}
	}
}
