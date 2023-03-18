import sys
array = []
for _ in range(9):
    array.append(list(map(int, sys.stdin.readline().split())))
num_list = []
for i in array:
    for j in i:
        num_list.append(j)

max_num = max(num_list)
idx = num_list.index(max_num) + 1
print(max_num)

# 2차원 리스트의 행렬 값은 1차원 리스트에서의 인덱스 값을
# 행렬 n * n에서의 n으로 나눈 몫과 나머지와 같음.
# 1차원 인덱스가 idx 라면, 2차원 인덱스는 (idx // n, idx % n)

a = idx // 9 + 1
b = idx % 9

if b == 0:
    a -= 1
    b = 9
print(a, b)
