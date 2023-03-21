# 수의 범위가 넓기 때문에 최빈값 계산하는 것이 관건임.
# count 함수로는 시간 초과가 나왔기 때문에 collections.Counter 이용함.
import sys
from collections import Counter
n = int(sys.stdin.readline())
array = []
# 리스트 생성
for _ in range(n):
    array.append(int(sys.stdin.readline()))
# 산술평균 출력
print(round(sum(array) / len(array)))
# 중앙값 출력
array.sort()
print(array[len(array) // 2])
# 최빈값 출력
ar = Counter(array)
if n > 1 and ar.most_common()[0][1] == ar.most_common()[1][1]:
    print(ar.most_common()[1][0])
else:
    print(ar.most_common()[0][0])
# 범위 출력
print(max(array) - min(array))
