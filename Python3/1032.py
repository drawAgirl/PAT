p,q,n = map(int,input().split())
dic = {}
for _ in range(n):
    cur,data,next = input().split()
    dic[int(cur)] = int(next)
verify = {}
while p != -1:
    verify[p] = 1
    p = dic[p]

flag = True
while q != -1:
    if verify.get(q) != None:
        print("%05d"%q)
        flag = False
        break
    else:
        verify[q] = 1
        q = dic[q]

if flag:
    print("-1")