m,n,k = map(int,input().split())
for _ in range(k):
    data = list(map(int,input().split()))
    ans = []
    flag = True
    cur = 0
    for i in range(1,n+1):
        ans.append(i)
        if len(ans) > m:
            flag  = False
            break
        while len(ans) and ans[-1] == data[cur]:
            del ans[-1]
            cur += 1
    if flag and len(ans) == 0:
        print("YES")
    else:
        print("NO")