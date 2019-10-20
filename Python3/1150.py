n,m = map(int,input().split())
g = {}
for _ in range(m):
    a,b,c = map(int,input().split())
    g[(a,b)] = g[(b,a)] = c
k=int(input())
path = -1
short_dis = 1e6
for i in range(1,k+1):
    distance = 0
    isNA = False
    _,*nodes = map(int,input().split())
    start = nodes[0]
    vis = {i:0 for i in range(1,n+1)}
    for node in nodes[1:]:
        if g.get((start,node)) is None:
            isNA = True
        else:
            distance += g[(start,node)]
        start = node
        vis[node] += 1
    print("Path %d: "%i,end='')
    if isNA:
        print("NA",end=' ')
    else:
        print(distance,end=' ')
    isCycle = True
    isSimple = True
    for each in vis.items():
        if each[1] == 0:
            isCycle = False
            break
        if each[1] > 1:
            isSimple = False
    if isNA == True or isCycle == False:
        print("(Not a TS cycle)")
    elif isSimple == False:
        if short_dis > distance:
            short_dis = distance
            path = i
        print("(TS cycle)")
    else:
        if short_dis > distance:
            short_dis = distance
            path = i
        print("(TS simple cycle)")
print("Shortest Dist(%d) = %d"%(path,short_dis))