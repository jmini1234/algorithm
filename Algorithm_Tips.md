### 약수를 구할때는 제곱근까지만 구하면 된다 ! 
- 대칭적이기 때문에
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
