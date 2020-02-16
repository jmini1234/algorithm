#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <deque>

using namespace std;

deque<int> dq;

//1021
// queue와는 다르게 맨 앞에도 값을 추가할 수 있어야하기 때문에 dequeue 사용 

int main() {

	int n, k;
	cin >> n >> k;

	//dq init
	for (int i = 1; i < n+1; i++) {
		dq.push_back(i);
	}

	//arr init
	int *arr = (int *)malloc(sizeof(int)*k);

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	int res = 0;

	for (int i = 0; i < k; i++) {

		//값이 다를때 
		// 해당 값이 어느 인덱스에 위치하는지 찾기
		int idx;
		for (int j = 0; j < dq.size(); j++) {
			if (arr[i] == dq.at(j)) {
				idx = j;
				break;
			}
		}

		//오른쪽으로 옮기기 
		if (idx > dq.size() / 2) {
			while (dq.front() != arr[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				res++;
			}
			dq.pop_front();
		}
		//왼쪽으로 옮기기
		else {
			while (dq.front() != arr[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				res++;
			}
			dq.pop_front();
		}
		

	}

	cout << res;

}
