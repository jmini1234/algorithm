a, b, c = map(int, input().split())

# a+1 만큼의 크기로 진행하자. 
# 2차원의 빈 배열이 생긴다. 
graph = [[] for _ in range(a + 1)]
visited = [False] * (a + 1)

# 배열 입력 받아 이차원 배열에 저장하기 
for _ in range(b):
    x, y = map(int, input().split())
		# 배열에 더하기 (1차원 배열에 더함)
    graph[x].append(y)

result = 0

def dfs(v):
    # 전역변수를 자용하기 때문에 global 붙여주기
    global result
		# 끝까지 방문한 곳이라면 return 해서 함수 종료
    if visited[v]:
        return
		# 그렇지 않다면 방문 후 count 하기 
    visited[v] = True
    result += 1
		# 해당 node와 인접해있는 모든 노드에 대해서 탐색하기 
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

# 시작 노드가 여러개이다.(즉 시작점이 여러개이다.)
for _ in range(c):
    v = int(input())
    dfs(v)
				
print(result)
