n,m=map(int,input().split())
g ={}
for i in range(m):
    a,b=map(int,input().split())
    if g.get(a) is None:
        g[a] = []
    if g.get(b) is None:
        g[b] = []
    g[a].append(i)
    g[b].append(i)
k=int(input())
for _ in range(k):
    vis = [False for i in range(m)]
    _,*nodes = map(int,input().split())
    for node in nodes:
        if g.get(node) is None:
            continue
        for edge in g[node]:
            vis[edge] = True
    if vis.count(False):
        print("No")
    else:
        print("Yes")