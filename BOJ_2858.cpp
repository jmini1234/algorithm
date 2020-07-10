#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <math.h>

using namespace std;

int main() {
	int R, B;
	cin >> R >> B;
	int w, l;

  // i의 범위를 무한대로 설정하자, 어차피 답이 나오면 return 0이 되기 때문에
  // 괜히 B보다 작다고 했다가 계속 틀림 
	for (int i = 1; ; i++) {
		if (B%i == 0) {
			int b_wid = i;
			int b_hei = B / i;
      // 수학적 계산으로 도출한 식
			if (((b_wid+1)+(b_hei+1))*2 == R) {
				cout << (b_hei + 2) << " " << (b_wid + 2);
				return 0;
			}
		}
	}

}

