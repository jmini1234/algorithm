#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stack>

using namespace std;
int N;
char *arr = (char *)malloc(sizeof(int)*N);

int main() {

 cin >> N;

 stack <int> st;

 for (int i = 0; i < N; i++) {
  cin >> arr[i];
 }

 for (int i = 0; i < N; i++) {

  char val = arr[i];
  // 후위 표기법 
  // 간단한 알고리즘 
  // 피연산자가 나오면 stack에 저장
  // 연산자가 나오면 스택에서 두개의 값 꺼내서 계산 후 스택에 다시 넣음 
  if (val >= '1' && val <= '9') {
   st.push(val - '0');
  }
  else {
   int b = st.top();
   st.pop();
   int a = st.top();
   st.pop();

   if (val == '+')
   {
    st.push(a + b);
   }
   else if (val == '-')
   {
    st.push(a - b);
   }
   else if (val == '/')
   {
    st.push(a / b);
   }
   else if (val == '*')
   {
    st.push(a * b);
   }
  }

 }
 cout << st.top();
}
