H, U, D, F = map(int, input().split())

day = 0
start_height = 0 # 초기 높이
dist = 0 # 올라간 거리
up_height = 0 # 오른 후의 높이
end_height = 0  # 미끄러진 후의 높이
down_height= U*F*0.01 # 미끄러진 거리 

while(1):
	dist = U-down_height*day
	up_height=start_height+dist
	end_height=up_height-D
	if (end_height>=H):
		print('Success', day)
		break
	if (dist<0):
		print('Failure')
		break
	start_height=end_height
	day+=1
  
