def dfs(start):
    global vis
    if start == cur:
        return
    vis[start] = True
    for each in g[start]:
        if vis[each] == False:
            dfs(each)

n,m,k = map(int,input().split())
g = {}
for i in range(1,n+1):
    g[i] = []
for _ in range(m):
    a,b = map(int,input().split())
    g[a].append(b)
    g[b].append(a)
check = list(map(int,input().split()))
for point in check:
    cur = point
    vis = [False for i in range(n+1)]
    block = 0
    for j in range(1,n+1):
        if j!= cur and vis[j] == False:
            dfs(j)
            block += 1
    print("%d"%(block-1))