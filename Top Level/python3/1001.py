from operator import attrgetter
n,m = map(int,input().split())
class edge:
    def __init__(self,u,v,cost,status):
        self.u = u
        self.v = v
        self.cost = cost
        self.status = status
Edges = []
for _ in range(m):
    u,v,c,status = map(int,input().split())
    Edges.append(edge(u,v,c,-status))
Edges.sort(key=attrgetter('status','cost'))
father = [i for i in range(n+1)]

def find_father(x,fa):
    a = x
    while x != fa[x]:
        x = fa[x]
    while a != fa[a]:
        z = fa[a]
        fa[a] = x
        a = fa[z]
    return fa[x]
ans = []
max_cost = 0
INF = 0xfffffff
for i in range(1,n+1):
    fa = father.copy()
    num = 0
    cost = 0
    for each in Edges:
        if num == n-2:  break
        u = each.u
        v = each.v
        if u == i or v == i:    continue
        fu = find_father(u,fa)
        fv = find_father(v,fa)
        if fu == fv:    continue
        fa[fu] = fv
        num += 1
        if each.status == 0:
            cost += each.cost
    if num == n-2:
        if cost > max_cost:
            max_cost = cost
            ans.clear()
            ans.append(i)
        elif cost == max_cost and max_cost != 0:
            ans.append(i)
    else:
        if max_cost != INF:
            max_cost = INF
            ans.clear()
        ans.append(i)
if len(ans) == 0:
    print(0)
else:
    for i,j in enumerate(ans):
        print(j,end='')
        if i != len(ans)-1:   print(' ',end='')
        else:   print()


