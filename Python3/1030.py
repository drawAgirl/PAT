n,m,start,end = map(int,input().split())
pre = [i for i in range(n)]
vis = [False for i in range(n)]
d = [1e6 for i in range(n)]
c = [1e6 for i in range(n)]
g = {}
for i in range(n):
    g[i] = []
cost = [ [1e6 for i in range(n)]for i in range(n)]
for _ in range(m):
    a,b,dis,t = map(int,input().split())
    g[a].append((dis,b))
    g[b].append((dis,a))
    cost[a][b] = cost[b][a] = t
d[start] = c[start] = 0
from  queue import PriorityQueue
q = PriorityQueue()
q.put((0,start))
while q.qsize():
    cur = q.get()
    if vis[cur[1]]:
        continue
    vis[cur[1]] = True
    for each in g[cur[1]]:
        distance = each[0]
        to = each[1]
        if vis[to] == False and distance+cur[0] < d[to]:
            d[to] = distance + cur[0]
            pre[to] = cur[1]
            c[to] = c[cur[1]] + cost[cur[1]][to]
            q.put((d[to],to))
        elif vis[to] == False and distance+cur[0] == d[to]:
            if c[to] > c[cur[1]] + cost[cur[1]][to]:
                c[to] = c[cur[1]] + cost[cur[1]][to]
                pre[to] = cur[1]
                q.put((d[to],to))
path = []
def dfs(s,d):
    if s != d:
        path.append(d)
        dfs(s,pre[d])
dfs(start,end)
print("{} ".format(start),end='')
for i in range(len(path)):
    print("{} ".format(path[len(path)-i-1]),end='')
print("{} {}".format(d[end],c[end]))