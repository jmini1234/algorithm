n, m = map(int,input().split())
arr=[]
visited = [[False for _ in range(m)]for _ in range(n)]
for i in range(n):
	alist = list(map(int,input().split()))
	arr.append(alist)
result_max=0
	
def bfs():
	global result_max
	copy = [[0 for _ in range(m)]for _ in range(n)]
	for i in range(m):
		for j in range(n):
			copy[j][i]=arr[j][i]
	res=0
	tmp = []
	for i in range(m):
		for j in range(n):
			if copy[j][i]==2:
				tmp.append((j,i))
	dx=[0,0,-1,1]
	dy=[-1,1,0,0]
	while tmp:
		y,x = tmp.pop(0)
		for i in range(4):
			xn = x+dx[i]
			yn = y+dy[i]
			if xn>=0 and xn<m and yn>=0 and yn<n:
				if copy[yn][xn]==0 :
					copy[yn][xn]=2
					tmp.append((yn,xn))
	for i in range(m):
		for j in range(n):
			if copy[j][i]==0:
				res+=1
	result_max = max(res,result_max)

# 벽을 세우는 함수 
def wall(cnt):
	if cnt==3:
		bfs()
		return
	for i in range(m):
		for j in range(n):
			if arr[j][i]==0:
				arr[j][i]=1
				wall(cnt+1)
				arr[j][i]=0
	
wall(0)
print(result_max)
	
# 0 중에서 고를 수 있는 세가지 경우의 수를 해서 1을 대입 한 후 (조합으로 구하기)
# 이를 구하는 과정은 dfs !?
# bfs 사용해서 2 옆의 0을 모두 2로 바꾸어준다. 
# 0의 개수를 count 해보고 
# max 값이면 update 한다.
