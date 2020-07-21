n, m = map(int,input().split())
miro = []

for i in range(n):
	miro.append(list(map(int,input())))
	
visited = [[False for _ in range(m)] for _ in range(n)]
size_list = [[0 for _ in range(m)] for _ in range(n)]
dx = [0,0,-1,1]
dy = [1,-1,0,0]


def bfs(y,x):
	queue=[(y,x)]
	while queue:
		y, x = queue.pop(0)
		for i in range(4):
			xn = x+dx[i]
			yn = y+dy[i]
			if xn>=0 and xn<m and yn>=0 and yn<n:
				if visited[yn][xn]==False and miro[yn][xn]==1:
					visited[yn][xn]=True
					# BFS에서 최단 거리 정할때에는 특정 점까지 가는 거리의 수를 새로운 그래프에 계속 저장
					size_list[yn][xn]=size_list[y][x]+1
					queue.append((yn,xn))
# def dfs(y,x):
# 	global cnt
# 	if y==n-1 and x==m-1:
# 		return
# 	cnt+=1
# 	visited[y][x]=True
# 	for i in range(4):
# 		xn = x+dx[i]
# 		yn = y+dy[i]
# 		if xn>=0 and xn<m and yn>=0 and yn<n:
# 			if visited[yn][xn]==False and miro[yn][xn]==1:
# 				print(yn,xn)
# 				dfs(yn,xn)
## dfs 시간 초과 날 수 도 있음 
bfs(0,0)
print(size_list[n-1][m-1]+1)
