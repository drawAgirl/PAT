n,k,p = map(int,input().split())
fac = [0]
temp = 1
idx = 1
while temp <= n:
    temp = pow(idx,p)
    fac.append(temp)
    idx += 1
max_fac = -1
cur = []
ans = []
def dfs(index,cnt,total,facsum):
    global max_fac,ans
    if cnt > k or total > n:
        return
    if cnt == k and total == n:
        if facsum > max_fac:
            max_fac = facsum
            ans = cur.copy()
            return
    if index - 1 >= 0:
        cur.append(index)
        dfs(index,cnt+1,total+fac[index],facsum+index)
        cur.pop()
        dfs(index-1,cnt,total,facsum)
dfs(len(fac)-1,0,0,0)
if max_fac == -1:
    print("Impossible")
else:
    print("%d = %d^%d"%(n,ans[0],p),end='')
    for i in range(1,len(ans)):
        print(" + %d^%d"%(ans[i],p),end='')
