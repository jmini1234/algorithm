#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <queue>

using namespace std;


int main() {
 int n, k;
 cin >> n >> k;
 queue <int> q;

 for (int i = 1; i < n+1; i++) {
  q.push(i);
 }

 cout << "<";

 while (q.size()) {
  if (q.size() == 1) {
   cout << q.front() << ">";
   q.pop();
   break;
  }
  for (int j = 1; j < k; j++) {
   q.push(q.front());
   q.pop();
  }
  cout << q.front()<<",";
  q.pop();

 }


}
