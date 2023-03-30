import re

n = int(input())
pattern = input()
lef_right = pattern.split('*')

p = re.compile(lef_right[0] + '[a-z]*' + lef_right[1])

for i in range(n):
    s = input()
    if p.match(s) is not None and len(p.match(s).group()) == len(s):
        print('DA')
    else:
        print('NE')