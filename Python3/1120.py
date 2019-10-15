n=int(input())
number = input().split()
a=set()
for num in number:
    cur = 0
    for s in num:
        cur += ord(s)-ord('0')
    a.add(cur)
print(len(a))
space = 0
a=list(a)
a.sort()
for each in a:
    print(each,end='')
    space += 1
    if space != len(a):
        print(' ',end='')