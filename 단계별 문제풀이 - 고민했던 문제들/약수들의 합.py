import sys
while True:
    n = int(sys.stdin.readline())
    if n == -1:
        quit()

    else:
        array = []
        l = ''
        for i in range(1, int(n ** 0.5) + 1):
            if n % i == 0:
                array.append(i)
                if n // i != i:
                    array.append(n // i)
        array.sort()
        if sum(array[:-1]) == n:
            for i in array[:-1]:
                l += ' + ' + str(i)
            print(f'{n} = {l[3:]}')
        else:
            print(f'{n} is NOT perfect.')
