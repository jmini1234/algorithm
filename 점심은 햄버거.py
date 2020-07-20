n=int(input()) #햄버거 개수
e=list(map(int,input().strip().split(' '))) #먹는데 걸리는 시간
h=list(map(int,input().strip().split(' '))) #데우는데 걸리는 시간

l=[(e[i],h[i]) for i in range(n)]

l= sorted(l,reverse=True) #먹는데 오래 걸리는 순서로 sort 해야한다. 

beginEat=0
tmp=0

for i in l:
	# beginEat에 데우는데 걸린 시간을 계속 더해줌 
	beginEat+=i[1]
	# 해당 햄버거를 다 데우고 먹는 시간과 tmp와 비교해서 더 큰 수를 tmp에 저장
	# (tmp는 가장 오래 걸린 데우고+먹는 중인 값)
	tmp=max(tmp,beginEat+i[0])

print(tmp)
