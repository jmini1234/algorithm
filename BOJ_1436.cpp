#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
int cnt = 0;
int num = 666;

bool IsMovieNum(int num) {
	int six = 0;
	int res = 0;
	while (num != 0) {
		if (num % 10 == 6) {
			six++;
			res = max(res, six);
		}
		else
			six = 0;
		num /= 10;
	}
	if (res >= 3)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (true) {
		if (IsMovieNum(num))
			cnt++;
		if (cnt == n)
			break;
		num++;
	}
	cout << num;


}
