s1 = input()
s2 = input()

d = [0] * 1000

for i in range(len(s1)):
    val = 0
    for j in range(len(s2)):
        if val < d[j]:
            val = d[j]
        elif s1[i] == s2[j]:
            d[j] = val + 1

print(max(d))
