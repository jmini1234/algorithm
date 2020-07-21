n = int(input())
danji = list()

for i in range(n):
	danji.append(list(map(int,input())))
	
dx = [0,0,-1,1]
dy = [-1,1,0,0]

visited = [[False for _ in range(n)] for _ in range(n)]
size = []
size_val = 0

def dfs(y,x):
	global size_val
	# 어차피 재귀로 돌아오기 때문에 여기서 방문 표시와 개수 count 진행
	size_val+=1
	visited[y][x]=True
	for i in range(4):
		ny=y+dy[i]
		nx=x+dx[i]
		if ny>=0 and ny<n and nx>=0 and nx<n:
			if danji[ny][nx]==1 and visited[ny][nx]==False:
				dfs(ny,nx)

cnt = 0

# 함수를 모든 좌표에서 실행하자 
# 어차피 visited를 통해 구분하기 때문에 방문했으면 dfs 진행되지 않는다.
for i in range(n):
	for j in range(n):
		if danji[j][i]==1 and visited[j][i]==False:
			# 방문 안한곳 있으면 size 0으로 해서 dfs 시작
			size_val=0
			dfs(j,i)
			# 다 끝나고 돌아올 떄 더해주기 
			size.append(size_val)

print(len(size))
size.sort()
for i in size:
	print(i)
