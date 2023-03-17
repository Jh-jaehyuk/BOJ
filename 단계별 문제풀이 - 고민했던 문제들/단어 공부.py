import sys
from collections import Counter
s = sys.stdin.readline().strip()
s = s.upper()
if len(s) == 1:
    print(s)
    quit()
s = Counter(s)

if s.most_common()[0][1] != s.most_common()[1][1]:
    print(s.most_common()[0][0])
else:
    print('?')

