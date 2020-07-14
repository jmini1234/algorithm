a, b, c = map(int, input().split())

# a+1 만큼의 크기로 진행해라 
graph = [[] for _ in range(a + 1)]
visited = [False] * (a + 1)

for _ in range(b):
    x, y = map(int, input().split())
    graph[x].append(y)

result = 0

def dfs(v):
    # 전역변수를 자용하기 때문에
    global result
    if visited[v]:
        return
    visited[v] = True
    result += 1
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

# 시작 노드가 여러개이다.
for _ in range(c):
    v = int(input())
    dfs(v)
				
print(result)
