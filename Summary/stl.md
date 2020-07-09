### STL

자주 사용되는 STL 자료구조
- sort 빠른 정렬
- min,max,minmax
- lower_bound, upper_bound 이분 탐색
- next_permutation 순열의 모든 경우의 수를 반환
- string 문자열
- vector 동적 배열

sort
```c++
std::sort(begin, end, compare)
defined in header <algorithm>
```
compare 함수를 직접 작성해서 정렬을 진행할 수 도 있다. 

string
- 메모리 관리를 stl에서 해준다. 
- 함수 사용이 직관적이다 
```c++
string.length()
defined in header <string>
```

vector 
- 크기를 알아서 관리해주는 동적 배열
- 메모리 관리를 직접 할 필요가 없다.
- 원하는 크기 값으로 초기화하기 편하다
- 일반적으로 정적 배열보다 느리다. 

```c++
vector<int> v : 크기 0인 int 배열
vector<int> v(n) : 크기 n인 int 배열
vector<int> v(n, -1) : 크기 n이고 초기값 -1인 배열
vector<vector<int>> M(n, vector<int>(m)): Mn×m
```
vector.size() : 크기 반환
vector.resize(n) : 크기를 n으로 설정
vector.emplace_back(v) : 맨 뒤에 원소 v추가
vector.pop_back() : 맨 뒤 원소 제거
