from queue import PriorityQueue
cMax,n,c,m = map(int,input().split())
weight = list(map(int,input().split()))
weight = list(map(lambda x:x-cMax//2,weight))
weight.insert(0,0)
vis = [False for i in range(n+1)]
d = [1e8 for i in range(n+1)]
pre =[[] for i in range(n+1)]
g = {i:[] for i in range(n+1)}
path = []
ans = []
minNeed = 1e8
minRemain = 1e8
for _ in range(m):
    a,b,dis = map(int,input().split())
    g[a].append((dis,b))
    g[b].append((dis,a))
q = PriorityQueue()
d[0] = 0
q.put((0,0))
while q.qsize():
    cur = q.get()
    if vis[cur[1]]:
        continue
    vis[cur[1]] = True
    for each in g[cur[1]]:
        dis = each[0]
        to = each[1]
        if vis[to] == False and dis+cur[0] < d[to]:
            d[to] = cur[0]+dis
            pre[to].clear()
            pre[to].append(cur[1])
            q.put((d[to],to))
        elif vis[to] == False and dis+cur[0] == d[to]:
            pre[to].append(cur[1])
            q.put((d[to],to))
def dfs(s):
    global minNeed,minRemain,ans,path
    if s==0:
        path.append(s)
        need = 0
        remain = 0
        for each in path[::-1]:
            if weight[each] > 0:
                remain += weight[each]
            else:
                if remain > abs(weight[each]):
                    remain -= abs(weight[each])
                else:
                    need += abs(weight[each])-remain
                    remain = 0
        if need< minNeed:
            minNeed = need
            minRemain= remain
            ans = path.copy()
        elif need == minNeed and remain < minRemain:
            minRemain = remain
            ans = path.copy()
        path.pop(a)
        return

    path.append(s)

    for each in pre[s]:
        dfs(each)
    path.pop()
dfs(c)
print(minNeed,end=' ')
for i,j in enumerate(ans[::-1]):
    print(j,end='')
    if i != len(ans)-1:
        print('->',end='')
    else:
        print(' %d'%minRemain)
