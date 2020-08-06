#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;

int main() {
	int N, P;
	cin >> N >> P;
	stack <int> v[7];
	// 2차원 stack처럼 생각

	int res = 0;
	for (int i = 0; i < N; i++) {
		int num, plat;
		cin >> num >> plat;
		// 아무것도 없을 때
		if (v[num].empty()) {
			v[num].push(plat);
			res++;
		}
		// stack에 값이 있을 때 
		else {
			while (1) {
				int val = v[num].top();
				if (val > plat) {
					res++;
					v[num].pop();
					// stack에 값이 없으면 break
					if (v[num].empty()) {
						res++;
						v[num].push(plat);
						break;
					}
				}
				else if (val == plat) {
					break;
				}
				// 작은 값이 있을 때 
				else {
					res++;
					v[num].push(plat);
					break;
				}
			}
		}
	}
	cout << res;
}
