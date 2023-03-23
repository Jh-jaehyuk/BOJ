import sys
n, k = map(int, sys.stdin.readline().split())
arr = [i for i in range(1, n + 1)]
idx = 0
i = 1
answer = []
while arr:
    if i <= k - 1:
        i += 1
        idx += 1
    else:
        answer.append(arr[idx])
        del arr[idx]
        i = 1
    # 인덱스가 인원수를 넘어가면
    if idx >= len(arr):
        idx = 0

s = ''
for i in answer:
    s += f'{str(i)}, '

print('<', end='')
print(s[:-2], end='')
print('>')
