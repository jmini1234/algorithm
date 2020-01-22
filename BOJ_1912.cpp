#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100000];

	int res[100000];

	for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	}

	//하나씩 더해가면서 작아지면 res에 저장하고 계속 진행해봄, res보다 커지면 계속 갱신

	int sum = 0;
	int tmp ;

	res[0] = arr[0];
	res[1] = arr[0] + arr[1];

	//if 12 차례인데 앞에서 나온 수가 음수이면 버려야함 !! 
	//21-35 = -14
	// 10 6 9 10 15 21 -14 12 33 32 
	for(int j=1;j<n;j++){
		tmp = arr[j];
		if(res[j-1]<0)
			res[j] = tmp;
		else 
			res[j] = tmp + res[j - 1];
	}


	sort(res, res + n);

	cout << res[n - 1];
}
