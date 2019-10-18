n,m = map(int,input().split())
indegree = [0 for i in range(n+1)]
g = {i:[] for i in range(1,n+1)}
for _ in range(m):
    a,b = map(int,input().split())
    indegree[b] += 1
    g[a].append(b)
k=int(input())
ans = []
for i in range(k):
    topo = list(map(int,input().split()))
    temp = indegree.copy()
    flag = True
    for num in topo:
        if temp[num] != 0:
            flag = False
            ans.append(i)
            break
        for each in g[num]:
            temp[each] -= 1
for each in ans:
    print(each,end='')
    if each != ans[-1]:
        print(' ',end='')


