class node: #也可以不用自定义 换成元组
    def __init__(self,to,dis):
        self.to = to
        self.dis = dis
    def __lt__(self, other): #重写<
        return self.dis < other.dis
from queue import PriorityQueue
n,m,c1,c2 = map(int,input().split())
weight = list(map(int,input().split()))
d = [1e5 for i in range(n)]
vis = [False for i in range(n)]
cnt = [1 for i in range(n)]
w = [0 for i in range(n)]
graph = {}
q = PriorityQueue()
for _ in range(m):
    a,b,c = map(int,input().split())
    if graph.get(a) is None:
        graph[a] = []
    graph[a].append([b,c])
    if graph.get(b) is None:
        graph[b] = []
    graph[b].append([a,c])
def Disjktra(s):
    d[s] = 0
    w[s] = weight[s]
    q.put(node(s,0))
    while q.qsize():
        cur = q.get()
        if vis[cur.to]:
            continue
        vis[cur.to] = True
        for each in graph[cur.to]:
            to = each[0]
            dis = each[1]
            if vis[to] == False and dis + cur.dis < d[to]:
                d[to] = dis + cur.dis
                w[to] = w[cur.to] + weight[to]
                cnt[to] = cnt[cur.to]
                q.put(node(to,d[to]))
            elif vis[to] == False and dis + cur.dis == d[to]:
                if w[to] < w[cur.to] + weight[to]:
                    w[to] = w[cur.to] + weight[to]
                    q.put(node(to,d[to]))
                cnt[to] += cnt[cur.to]
Disjktra(c1)
print("%d %d"%(cnt[c2],w[c2]))




