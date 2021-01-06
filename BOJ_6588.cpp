#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n;
vector<bool> flag(1000001, true);
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 2; i < 1000001; i++) {
		if (flag[i]) {
			for (int j = 2 * i; j < 1000001; j += i)
				flag[j] = false;
		}
	}

	while (1) {
		int num; cin >> num;
		if (num == 0)
			exit(0);

		bool solved = false;
		for (int i = 2; i < num; i++) {
			if (flag[i] && flag[num - i]) {
				cout << num << " = " << i << " + " << num - i << '\n';
				solved = true;
				break;
			}
		}
		if (!solved) {
			cout << "Goldbach's conjecture is wrong\n";
		}
	}
}
