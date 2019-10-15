from queue import PriorityQueue
n, m = map(int, input().split())
d = [1e9 for i in range(n)]
t = [1e9 for i in range(n)]
g = [[] for i in range(n)]
gg = [[] for i in range(n)]
cost_time = [1e9 for i in range(n)]
TIME = [[1e9 for j in range(n)] for i in range(n)]
pre = [i for i in range(n)]
another_pre = [[] for i in range(n)]
short_path = []
fast_path = []
temp = []
for _ in range(m):
    v1,v2,one_way,distance,need_time = map(int,input().split())
    g[v1].append((distance,v2))
    gg[v1].append((need_time,v2))
    TIME[v1][v2] = need_time
    if one_way == 0:
        g[v2].append((distance,v1))
        gg[v2].append((need_time,v1))
        TIME[v2][v1] = need_time
start,destination = map(int,input().split())
def dijkstra_short(s):
    vis = [False for i in range(n)]
    d[s] = 0
    cost_time[s] = 0
    q = PriorityQueue()
    q.put((0,s))
    while q.qsize():
        cur = q.get()
        if vis[cur[1]]:
            continue
        vis[cur[1]] = True
        for each in g[cur[1]]:
            dis = each[0]
            to =  each[1]
            if vis[to] == False and dis + cur[0] < d[to]:
                d[to] = cur[0] + dis
                cost_time[to] = cost_time[cur[1]]  +TIME[cur[1]][to]
                pre[to] = cur[1]
                q.put((d[to],to))
            elif vis[to] == False and dis + cur[0] == d[to]:
                if cost_time[to] > cost_time[cur[1]] + TIME[cur[1]][to]:
                    cost_time[to] = cost_time[cur[1]] + TIME[cur[1]][to]
                    pre[to] = cur[1]
                    q.put((d[to],to))
def dfs_short(s):
    if s == start:
        short_path.append(s)
        return
    global pre
    short_path.append(s)
    dfs_short(pre[s])

def dijkstra_fast(s):
    vis = [False for i in range(n)]
    t[s] = 0
    q = PriorityQueue()
    q.put((0,s))
    while q.qsize():
        cur = q.get()
        if vis[cur[1]]:
            continue
        vis[cur[1]] = True
        for each in gg[cur[1]]:
            time = each[0]
            to = each[1]
            if vis[to] == False and time + cur[0] < t[to]:
                t[to] = time + cur[0]
                another_pre[to].clear()
                another_pre[to].append(cur[1])
                q.put((t[to],to))
            elif vis[to] == False and time + cur[0] == t[to]:
                t[to] = time + cur[0]
                another_pre[to].append(cur[1])
                q.put((t[to],to))
def dfs_fast(s):
    global fast_path
    if s == start:
        if len(temp) < len(fast_path) or len(fast_path) == 0:
            fast_path = temp.copy()
            fast_path.append(s)
        return
    temp.append(s)
    for each in another_pre[s]:
        dfs_fast(each)
    temp.pop()


dijkstra_short(start)
dfs_short(destination)
dijkstra_fast(start)
dfs_fast(destination)

if short_path == fast_path:
    print("Distance = {}; Time = {}: ".format(d[destination],t[destination]),end='')
    for station in short_path[::-1]:
        print(station,end='')
        if station != destination:
            print(" -> ",end='')
        else:
            print()
else:
    print("Distance = %d: "%d[destination],end='')
    for station in short_path[::-1]:
        print(station, end='')
        if station != destination:
            print(" -> ", end='')
        else:
            print()
    print("Time = %d: " % t[destination], end='')
    for station in fast_path[::-1]:
        print(station, end='')
        if station != destination:
            print(" -> ", end='')
        else:
            print()
