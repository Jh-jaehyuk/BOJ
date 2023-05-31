s = input()
operator = '+/*-'

x = 0
for i in operator:
    if i in s:
        s = s.split(i)
        a, b = s[0], s[1]
        if a == '':
            a = '-' + s[1]
            b = s[2]
        a, b = int(a, 8), int(b, 8)

        if i == '+':
            x = a + b
        elif i == '-':
            x = a - b
        elif i == '*':
            x = a * b
        else:
            if b == 0:
                print('invalid')
                quit(0)
            x = a // b
        break

print(oct(x)[2:] if x >= 0 else '-' + oct(x)[3:])
