import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
stack = []
# 값이 없으면 -1 이므로 -1로 초기화
answer = [-1] * len(arr)

for i in range(len(arr)): # i 는 각 배열의 인덱스
    # 스택의 맨 위의 값보다 배열의 값이 더 크면
    while stack and arr[stack[-1]] < arr[i]:
        # 스택의 값을 빼고 정답에 arr[i] 를 저장
        answer[stack.pop()] = arr[i]
    # while를 나오면 arr[i]를 stack에 저장.
    stack.append(i)
print(*answer)
