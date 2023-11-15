import sys

K, L = map(int, sys.stdin.readline().split())
num_dict = dict()
idx_dict = dict()

for i in range(L):
    num = sys.stdin.readline().rstrip()
    num_dict[num] = i
    idx_dict[i] = num

for val in sorted(num_dict.values()):
    print(idx_dict[val])
    K -= 1
    if K == 0:
        break
