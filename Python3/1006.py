n = int(input())
d = []
for _ in range(n):
    a = list(map(str,input().split()))
    d.append(a)
d=sorted(d,key=lambda x:x[1])
print(d[0][0],end=' ')
d=sorted(d,key=lambda x:x[2],reverse=True)
print(d[0][0])