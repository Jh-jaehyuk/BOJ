import sys

k = int(sys.stdin.readline())
arr = list(sys.stdin.readline().rstrip().split())
visited = [False] * 10
max_num = ''
min_num = ''

def check(i, j, k):
    if k == '<':
        return i < j
    else:
        return i > j

def dfs(count, s):
    global max_num, min_num

    if count == (k + 1):
        if len(min_num) == 0:
            min_num = s
        else:
            max_num = s
        return

    for i in range(10):
        if not visited[i]:
            if count == 0 or check(s[-1], str(i), arr[count - 1]):
                visited[i] = True
                dfs(count + 1, s + str(i))
                visited[i] = False

dfs(0, '')
print(max_num)
print(min_num)
