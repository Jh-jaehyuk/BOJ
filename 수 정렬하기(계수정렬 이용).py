import sys
n = int(sys.stdin.readline())

count = [0] * 10001

for _ in range(n):
    num = int(sys.stdin.readline())
    count[num] += 1  # 각 데이터에 해당하는 인덱스의 값 증가

for i in range(1, 10001):  # 리스트에 기록된 정렬 정보 확인
    if count[i] != 0:
        for _ in range(count[i]):
            print(i)
