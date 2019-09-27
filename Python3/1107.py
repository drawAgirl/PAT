n = int(input())
father = [i for i in range(n+1)]
course = [0*i for i in range(1001)]
root = course.copy()
def findfather(n):
    t = n
    while n != father[n]:
        n = father[n]
    while t != father[t]:
        z = t
        t = father[t]
        father[z] = n
    return n
def Union(a,b):
    fa = findfather(a)
    fb = findfather(b)
    if fa != fb:
        father[fa] = fb
for i in range(1,n+1):
    a,*b = input().split()
    b = list(map(int,b))
    for each in b:
        if course[each] == 0:
            course[each] = i
        else:
            Union(i,course[each])
for i in range(1,n+1):
    baba = findfather(i)
    root[baba] += 1
root = sorted(list(filter(lambda x:x!=0,root)),reverse=True)
print("%d"%len(root))
for i in range(len(root)):
    print("%d"%root[i],end='')
    if i != len(root)-1:
        print(" ",end='')