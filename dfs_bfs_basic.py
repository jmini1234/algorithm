n, m, start = map(int,input().split())

dist = [[0 for _ in range(n+1)] for _ in range(n+1)]
dfs_visited = [False for _ in range(n+1)]
bfs_visited = [False for _ in range(n+1)]
dfs_list = []
bfs_list = []

for i in range(m):
	a, b = map(int,input().split())
  # 양방향에 설정해 주어야 하는 것이 중요하다
	dist[a][b]=1
	dist[b][a]=1

dfs_cnt = 0

def dfs(v):
	dfs_list.append(v)
  # 가장 먼저 시작점 방문한다. 
	dfs_visited[v]=True
	for i in range(1, n+1):
    # 해당 시작점과 연결되어있는 점들 중에서 하나씩 깊게 들어가본다.
		if dist[v][i]==1 and dfs_visited[i]==False:
			dfs(i)

def bfs(v):
  # queue를 설정하고 queue가 없을때까지 진행하는 것은 외우기 !!!!!
	queue = [v]
	while queue:
    # 맨 앞 value 하나 꺼내서 true 만들어서 방문하고 
		val = queue.pop(0)
		bfs_visited[val]=True
		bfs_list.append(val)
    # 그 값과 관련되어 있는 정점들 중 아직 방문하지 않은 점과 queue에 존재하지 않는 점을 queue에 더해주고 다시 맨 앞 값을 꺼내준다.
		for i in range(1,n+1):
			if dist[val][i]==1 and bfs_visited[i]==False and i not in queue:
				queue.append(i)
	
dfs(start)
for i in range(len(dfs_list)):
	if i!=len(dfs_list)-1:
		print(dfs_list[i],end=' ')
	else:
		print(dfs_list[i])


bfs(start)
for i in range(len(bfs_list)):
	if i!=len(dfs_list)-1:
		print(bfs_list[i],end=' ')
	else:
		print(bfs_list[i],end='')
