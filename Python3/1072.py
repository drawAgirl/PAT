from queue import  PriorityQueue
n,m,k,dis_max = map(int,input().split())
g = {i:[] for i in range(n+m+1)}
vis = []
d = []
def dijkstra(s):
    global vis,d
    vis = [False for i in range(n+m+1)]
    d = [1e6 for i in range(n+m+1)]
    d[s] = 0
    q = PriorityQueue()
    q.put((0,s))
    while q.qsize():
        cur = q.get()
        if vis[cur[1]]:
            continue
        vis[cur[1]] = True
        for each in g[cur[1]]:
            dis = each[0]
            to = each[1]
            if vis[to]==False and dis+cur[0] < d[to]:
                d[to] = dis+cur[0]
                q.put((d[to],to))
def to_int(c):
    if c[0] == 'G':
        ind = int(c[1:])+n
    else:
        ind = int(c)
    return ind
for _ in range(k):
    c1,c2,dis = input().split()
    x = to_int(c1)
    y = to_int(c2)
    dis = int(dis)
    g[x].append((dis,y))
    g[y].append((dis,x))
ans_index = -1
min_dis = -1
min_average = 0
for i in range(n+1,n+m+1):
    dijkstra(i)
    total = sum(d[1:n+1])/n
    cur_max = max(d[1:n+1])
    if cur_max > dis_max:
        continue
    cur_min = min(d[1:n+1])
    if min_dis < cur_min:
        min_dis = cur_min
        ans_index = i
        min_average = total
    elif min_dis == cur_min:
        if min_average > total:
            min_average = total
            ans_index = i
if ans_index == -1:
    print("No Solution")
else:
    print("G{}".format(ans_index-n))
    print("{:.1f} {:.1f}".format(min_dis,min_average+0.005))







