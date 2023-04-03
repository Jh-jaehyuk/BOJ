import sys
from collections import deque

s = int(sys.stdin.readline())
queue = deque([[1, 0, 0]])
visited = [[False] * 1001 for _ in range(1001)]

visited[1][0] = True

while queue:

    screen, clip, count = queue.popleft()

    if screen == s:
        print(count)
        break

    for i in range(3):
        if i == 0:
            clip_new, screen_new = screen, screen

        elif i == 1:
            screen_new, clip_new = screen + clip, clip

        else:
            screen_new, clip_new = screen - 1, clip

        if screen_new >= 1001 or screen < 0 or clip_new >= 1001 or clip_new < 0 \
                or visited[screen_new][clip_new]:
            continue

        visited[screen_new][clip_new] = True
        queue.append([screen_new, clip_new, count + 1])
