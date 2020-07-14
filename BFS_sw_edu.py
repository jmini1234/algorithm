from collections import deque

l = int(input())

# -1로 초기화 하기 (아직 방문하지 않은 곳, 따로 visited를 만들지 않고도 진행하기 위해)
graph = [[-1] * l  for _ in range(l)]

# 시작 위치 
start_x, start_y = map(int, input().split())
# 도착 위치 
target_x, target_y = map(int, input().split())

# 갈 수 있는 이동경로 경우의 수 다시보기 ! 
dx = [-1,-2, -2, -1, 1, 2, 2, 1]
dy = [-2,-1, 1, 2, 2, 1, -1, -2]

# BFS 메서드 정의
# 결국 모든 점으로 가는데 걸리는 횟수를 각 이차원 배열에 저장한다. 
def bfs(start_x,start_y):
		# 처음 위치 방문, 시작 위치의 이동 칸 수는 0
		graph[start_x][start_y] = 0
		# 큐에 좌표를 넣는다.
		q = deque[(start_x, start_y)]
		# queue가 모두 없어질때까지 
		while q:
				# 하나 꺼내서 모든 인접한 node를 탐색해서 저장한다. (나이트가 갈 수 있는 위치)
				x, y= queue.popleft()
				for i in range(8):
					nx = x+dx[i]
					ny = y+dy[i]
					if 0<=nx and nx<l and 0<=ny and ny<l
							continue
					# 방문한 횟수를 graph 배열에 저장하고
					graph[nx][ny] = graph[x][y]+1
					# q에 넣는다.
					q.append[(nx,ny)]

bfs(start_x,start_y)
print(graph[target_x][taret_y])
