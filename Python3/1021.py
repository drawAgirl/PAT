n=int(input())
g = {i:[] for i in range(1,n+1)}
vis = [False for i in range(n+1)]
for _ in range(1,n):
    a,b = map(int,input().split())
    g[a].append(b)
    g[b].append(a)
max_height = 0
ans = []
def dfs(root,height):
    global max_height,ans
    if height > max_height:
        max_height = height
        ans.clear()
        ans.append(root)
    elif height == max_height:
        ans.append(root)
    vis[root] = True
    for each in g[root]:
        if vis[each]:
            continue
        dfs(each,height+1)
s = set()
cnt = 0
for i in range(1,n+1):
    if vis[i]:
        continue
    dfs(i,1)
    if i == 1:
        if len(ans) != 0 :
            s1 = ans[0]
        for each in ans:
            s.add(each)
    cnt += 1
if cnt > 1:
    print("Error: %d components"%cnt)
else:
    ans.clear()
    max_height = 0
    vis = [False for i in range(n+1)]
    dfs(s1,1)
    for each in ans:
        s.add(each)
    ss = sorted(s)
    for each in ss:
        print(each)