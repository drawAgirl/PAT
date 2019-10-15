n,m = map(int,input().split())
g = [[False for i in range(n+1)] for j in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    g[a][b] = g[b][a] = True
k = int(input())
for _ in range(k):
    v,*path = map(int,input().split())
    s = set(path)
    if path[0] != path[-1] or v != n+1 or len(s) != n:
        print("NO")
        continue
    flag = True
    for i in range(v-1):
        if g[path[i]][path[i+1]] == False:
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")
