import sys

n, m = map(int, sys.stdin.readline().split())
# 집합을 이용하기 위해 리스트가 아닌 세트로 정의.
arr1 = set()
arr2 = set()

for _ in range(n):
    arr1.add(sys.stdin.readline().rstrip())
for _ in range(m):
    arr2.add(sys.stdin.readline().rstrip())

# arr1 과 arr2에 공통으로 들어있는 이름을 구함
# == 교집합
arr = list(arr1 & arr2)
# 알파벳 순서로 정렬하기 위함.
arr.sort()

print(len(arr))
for i in arr:
    print(i)
