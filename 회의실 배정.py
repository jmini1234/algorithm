
n = int(input())
begin = [0 for _ in range(101)]
end = [0 for _ in range(101)]

for i in range(n):
	begin[i], end[i] = list(map(int,input().strip().split(' ')))

# 끝나는 시간 순으로 정렬하기, 끝나는 시간 중에서 같으면 시작 시간이 작은 순으로 
order = [(end[i], begin[i]) for i in range(n)]
order.sort()
	
def schedule():
	earlist=0 #회의를 시작할 수 있는 시간
	selected=0 #회의 개수
	
	for i in range(n):
		mbegin=order[i][1]
		mend=order[i][0]
		
		if(earlist<=mbegin):
			earlist=mend
			selected+=1

	return selected

print(schedule())
