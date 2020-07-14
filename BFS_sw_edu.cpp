from collections import deque

l = int(input())

graph = [[-1] * l  for _ in range(l)]

# 시작 위치 
start_x, start_y = map(int, input().split())
# 도착 위치 
target_x, target_y = map(int, input().split())

# 갈 수 있는 이동경로 경우의 수 다시보기 ! 
dx = [-1,-2, -2, -1, 1, 2, 2, 1]
dy = [-2,-1, 1, 2, 2, 1, -1, -2]

# BFS 메서드 정의
# 결국 모든 점으로 가는데 걸리는 횟수를 각 이차원 배열에 저장하는 것이다. 
def bfs(start_x,start_y):
		# 처음 위치 방문
		graph[start_x][start_y] = 0
		# 큐에 넣는다.
		q = deque[(start_x, start_y)]
		# 하나 빼서 인접한 경우 모두 살펴본다. 
		while q:
				x, y= queue.popleft()
				for i in range(8):
					nx = x+dx[i]
					ny = y+dy[i]
					if 0<=nx and nx<l and 0<=ny and ny<l
							continue
					# 방문한 횟수를 graph에 저장 
					graph[nx][ny] = graph[x][y]+1
					q.append[(nx,ny)]

bfs(start_x,start_y)
print(graph[target_x][taret_y])
