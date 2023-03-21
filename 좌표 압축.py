# list.index()는 O(N)이지만 list[]는 O(1) 시간 복잡도를 가짐.
import sys

n = int(sys.stdin.readline())
array = list(map(int, sys.stdin.readline().split()))
# 배열에 중복 원소 제거
l = sorted(set(array))
# 중복을 제거한 배열에서 원소의 값을 key,
# 원소의 인덱스를 value로 받는 딕셔너리 생성
d = {l[i]:i for i in range(len(l))}
for i in array:
    print(d[i], end=' ')
