#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;

int main()
{
 int x, y, r, n;
 int res = 0;
 cin >> x >> y >> r >> n;

 for (int i = 0; i < n; i++) {
  int x1, y1;
  cin >> x1 >> y1;
  // 루트 계산법 ! sqrt 
  double cal = sqrt(pow(2, abs(x1 - x)) + pow(2, abs(y1 - y)));
  //반지름보다 거리가 작거나 같으면 안에 있음 
  if (cal <= r)
   res++;
 }

 cout << res;
}
