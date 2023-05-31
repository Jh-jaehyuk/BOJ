import sys
import heapq

T = int(sys.stdin.readline())

for _ in range(T):
    k = int(sys.stdin.readline())
    check = [False] * k
    max_arr = []
    min_arr = []

    for i in range(k):
        a, b = sys.stdin.readline().split()
        b = int(b)

        if a == 'I':
            heapq.heappush(min_arr, (b, i))
            heapq.heappush(max_arr, (-b, i))
            check[i] = True

        else:
            if b == 1:
                while max_arr and not check[max_arr[0][1]]:
                    heapq.heappop(max_arr)
                if max_arr:
                    check[max_arr[0][1]] = False
                    heapq.heappop(max_arr)

            if b == -1:
                while min_arr and not check[min_arr[0][1]]:
                    heapq.heappop(min_arr)
                if min_arr:
                    check[min_arr[0][1]] = False
                    heapq.heappop(min_arr)

    while min_arr and not check[min_arr[0][1]]:
        heapq.heappop(min_arr)
    while max_arr and not check[max_arr[0][1]]:
        heapq.heappop(max_arr)

    if min_arr and max_arr:
        print(-max_arr[0][0], min_arr[0][0])
    else:
        print('EMPTY')

# 참고 : https://chaewsscode.tistory.com/138
