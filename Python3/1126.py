n,m=map(int,input().split())
g = [[] for i in range(n+1)]
vis = [False for i in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    g[a].append(b)
    g[b].append(a)
cnt = 0
def dfs(s):
    global cnt
    if vis[s]:  return
    vis[s] = True
    cnt += 1
    for each in g[s]:
        dfs(each)
dfs(1)
even_cnt = 0
odd_cnt = 0
for i in range(1,n+1):
    print(len(g[i]),end='')
    if i != n:  print(" ",end='')
    else:   print()
    if len(g[i]) & 1:   odd_cnt += 1
    else:   even_cnt += 1
if cnt != n:
    print("Non-Eulerian")
elif odd_cnt == 0 and even_cnt == n:
    print("Eulerian")
elif odd_cnt == 2 and even_cnt == n-2:
    print("Semi-Eulerian")
else:
    print("Non-Eulerian")