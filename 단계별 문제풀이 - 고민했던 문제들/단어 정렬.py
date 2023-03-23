import sys
n = int(sys.stdin.readline())
array = []
for _ in range(n):
    array.append(sys.stdin.readline().rstrip())
# 중복 단어 제거
array = list(set(array))
# 길이 순서대로 정렬하고, 길이가 같으면 알파벳 순서대로 정렬
array = sorted(array, key=lambda x:(len(x), x))
for i in array:
    print(i)
