import sys
import string

def ten_to_n(n, base): # 10진수 n을 base진수로 변환
    tmp = string.digits + string.ascii_uppercase
    q, r = divmod(n, base)
    if q == 0:
        return tmp[r]
    else:
        return ten_to_n(q, base) + tmp[r]

n, b = map(int, sys.stdin.readline().split())
print(ten_to_n(n, b))
