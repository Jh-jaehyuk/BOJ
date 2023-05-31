n = int(input())
arr = list(map(int, input().split()))
count_arr = [0] * 41

for i in arr:
    count_arr[i] += 1

tmp = 2

for count in count_arr:
    if count > tmp:
        print(0)
        quit(0)
    tmp = count

x = count_arr.count(2)
if 1 in count_arr:
    print(2 ** (x + 1))
else:
    print(2 ** x)
