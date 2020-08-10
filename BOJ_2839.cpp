#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);

	int min_val = 10000;
	int val = 0;
	int tmp = n;
	bool flag = false;
	if (tmp % 5 == 0) {
		cout << tmp / 5;
		return 0;
	}
	else {
		while (tmp / 5 != 0) {
			val += 1;
			tmp -= 5;
			if (tmp % 3==0) {
				flag = true;
				min_val = min(val + tmp/3, min_val);
			}
		}
	}
	if (flag == true)
		cout << min_val;
	else if (flag == false && n % 3 == 0)
		cout << n / 3;
	else
		cout << -1;
	

}
