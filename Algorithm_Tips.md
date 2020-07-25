### 약수를 구할때는 제곱근까지만 구하면 된다 ! 
- 대칭적이기 때문에
- 소수 
```python
import math

def find_all_divisors_of_a_number(x):
  result=[]
  // 제곱근까지만 일때 
  for i in range(1, int(math.sqrt(x))+1)):
    // 약수이면
    if x % i == 0:
      result.append(i)
      // 제곱인 약수가 아니면 
      if i*i!=x:
        // 대칭적인 약수와 i를 곱하면 x 값이 나오기 때문에
        result.append(x//i)
  return result
  
  a, b = map(int, input().split())
  for i in range(a, b+1):
    if sum(find_all_divisisors_of_a_number(i)) - i ==i:
      print(i, end=' ')
    
```

### 수분할 아이디어
``` 입력받은 수를 1,2,3의 조합으로 나타낼 수 있는 경우의 수는 ? ```
#### DP : 재귀를 사용해서 최적화된 결과를 도출
항상 이전의 경우에서 발전되는 경우만 있다 ! </br>
**점화식 : d[i] = d[i-1]+d[i-2]+d[i-3]**

```python
n = int(input())
d = [0] * n+1
d[1] = 1
d[2] = 2
d[3] = 4
for i in range(4, n+1):
  d[i] = d[i-1]+d[i-2]+d[i-3]
print(d[n])
```
- 비슷한 문제: 계단 오르기

#### DFS
깊이 우선 탐색
스택 자료구조를 이용 or 재귀 함수 이용
1. 시작 노드를 스택에 삽입하고 방문 처리
2. 스택의 최상단 노드에 방문하지 않은 인접한 노드가 하나라도 있으면 방문 처리 (주로 가장 작은 노드부터)
3. 더이상 진행 할 노드가 없으면 간선을 따라 뒤로 돌아간다. 
```python
def dfs(graph, v, visited):
  # 현재 노드를 방문함 
  visited[v] = True
  print(v, end=' ')
  # 현재 노드와 연결된 다른 노드를 재귀적으로 방문 (graph 배열에 저장되어있는 노드)
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)
# 각 노드가 연결 된 정보 표현 (2차원 리스트)
graph = [
  [],
  [2, 3, 8],
  [1, 7],
  ...
  ]
  # node의 개수 + 1로 설정, 첫번째는 사용하지 않는다. 
  visited = [Flase] * 9
  
  dfs(graph, 1, visited)
  
```
- 사용 문제 : 2차원 배열에서의 음료수 얼려 먹기 (2차원 배열을 그래프 -> 탐색)
              연결되어 있을 때만 얼릴 수 있기 때문에 연결되어 있음 
#### BFS
너비 우선 탐색
큐를 사용
1. 시작 노드를 큐에 삽입하고 방문 처리
2. 시작 노드와 연결되어있는 모든 노드를 큐에 삽입
3. 아래 노드부터 뽑아서 1~2 반복
```python 
from collections import deque
def bfs(graph, start, visited):
  queue = dequeue([start])
  visited[start] = True
  while queue:
    v = queue.popleft()
    for i in graph[v]:
      if not visited[i]:
        queue.append(i)
        visited[i] = True
```
- 사용 문제 : 미로탐색 

### 가장 작은 범위부터 구현하자 

### 시간 복잡도 관련 준비
1초는 약 10^8 이다. 
만약에 
```c++
while(temp){
  sum += temp%10;
  temp/=10;
}
```
이면 temp는 10씩 나누어지기 때문에 시간 복잡도는 **O(logn)** 이다.
- 상수 시간 O(1) : 사칙연산, 대입, 정수 실수 대소 비교 (!문자열의 비교는 상수 시간이 아니라 문자열의 길이에 따른 O(n)이다.)
- 지수 시간 O(log n) : 이분 탐색, 우선 순위 큐에서 원소 삽입, 삭제, 세그먼트 트리에서 구간합 구하기, 원소 수정, 균형 잡힌 이진 검색 트리에서 원소 검색, 추가, 삭제 
- 선형 지수 시간 O(n log n) : 퀵 정렬, 병합 정렬, LIS 발견
- 제곱 시간 O(n^2) : 정렬된 데이터의 퀵 정렬, 버블 정렬, 셀렉션 정렬

### 순열, 조합 c++ library
- next_permutation(arr,arr+n) : arr 배열의 다음 순열을 arr에 반환한다. 존재하면 True, 아니면 False
- prev_permutation(arr,arr+n) : arr 배열의 이전 순열을 arr에 반환한다. 존재하면 True, 아니면 False

### 메모이제이션
점화식-> 재귀함수
(기저사건) -> (점화식도 반환) -> 재귀
cache 초기화 -> 점화식 진행 중 나올 수 없는 값
재귀 들어가기 직전에 cache에 넣은 적이 있는지 확인 (있으면 return , 없으면 재귀)

### 계산이 어려울 때는 
- 전체에서 반대 경우 빼기 
  - 대칭하지 않는 타일의 경우의 수 구하기 (전체 경우의 수 - 대칭하는 타일의 경우의 수)
- 구하는 결과 바꾸어서 생각하기
  - 두 날짜의 차이를 구할 때 차이를 세지말고 (전체 ~ 끝 날짜의 날짜 수) + (전체 ~ 시작 날짜의 날짜 수) 로 구한다. 
  
### c++ sort 방법 
```c++
// O(nlogn)의 시간복잡도를 보장함
sort(arr,arr+n)
sort(&arr[0],&arr[n])
// 오름차순 변경 후 -> 내림차순
sort(vec.begin(),vec.end())
reverse(vec.begin(),vec.end()); // 내림차순

bool comp(const int &a, const int &b){
  retrun a>b; // 이 순서가 맞으면 true이니까 내림차순이다.
}

sort(arr,arr+n,comp) 
```
- stable한 정렬을 해야할 때 (모두 같다면 입력된 순으로)
  - struct에 idx추가해서 comp 함수에 조건 추가
  - stable_sort() 함수 사용해서 정렬
- 숫자, 문자 섞여있을때는 숫자 -> 문자 순으로 정렬됨

#### 다앙한 정렬 방법
- Bubble sort : **O(n^2)**, 앞에서부터 뒤로 하나씩 비교하면서 가장 큰 값을 고정시킨다. 
- Insert sort : **O(n^2)**, 앞에서부터 해당 idx 앞의 값 중 어느 곳에 들어가야하는지 고른다.
- Merge sort : 항상 **O(nlogn)** 쪼개는건 재귀 / 분할 정복 
- Heap sort : **O(n)** max heap -> tree의 root가 아래 자식보다 커야 한다. max_heap을 통해 최대값을 구하고 최대값을 맨 뒤로 보내면서 정렬
