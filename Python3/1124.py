m,n,s = map(int,input().split())
cnt = 0
vis = {}
flag = False
for i in range(1,m+1):
    name = input()
    cnt += 1
    if i == s:
        print(name)
        cnt = 0
        vis[name] = 1
        flag = True
        continue
    if flag and cnt == n:
        if vis.get(name) is None:
            vis[name] = 1
            cnt = 0
            print(name)
        else:
            cnt -= 1
if len(vis) == 0:
    print("Keep going...")