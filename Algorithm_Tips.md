### 약수를 구할때는 제곱근까지만 구하면 된다 ! 
- 대칭적이기 때문에
```python
import math

def find_all_divisors_of_a_number(x):
  result=[]
  // 제곱근까지만 일때 
  for i in range(1, int(math.sqrt(x))+1)):
    // 약수이면
    if x % i == 0:
      result.append(i)
      // 제곱인 약수가 아니면 
      if i*i!=x:
        // 대칭적인 약수와 i를 곱하면 x 값이 나오기 때문에
        result.append(x//i)
  return result
  
  a, b = map(int, input().split())
  for i in range(a, b+1):
    if sum(find_all_divisisors_of_a_number(i)) - i ==i:
      print(i, end=' ')
    
```

### 수분할 아이디어
``` 입력받은 수를 1,2,3의 조합으로 나타낼 수 있는 경우의 수는 ? ```
#### DP : 재귀를 사용해서 최적화된 결과를 도출
항상 이전의 경우에서 발전되는 경우만 있다 ! </br>
**점화식 : d[i] = d[i-1]+d[i-2]+d[i-3]**

```python
n = int(input())
d = [0] * n+1
d[1] = 1
d[2] = 2
d[3] = 4
for i in range(4, n+1):
  d[i] = d[i-1]+d[i-2]+d[i-3]
print(d[n])
```
- 비슷한 문제: 계단 오르기
