n,k = map(int,input().split())
idx = 0
name_to_int = {}
g = {}
for _ in range(n):
    a,b,t = input().split()
    if name_to_int.get(a) is None:
        name_to_int[a] = idx
        g[idx] = []
        idx += 1
    if name_to_int.get(b) is None:
        name_to_int[b] = idx
        g[idx] = []
        idx += 1
    t = int(t)
    g[name_to_int[a]].append((name_to_int[b],t))
vis = [False for i in range(idx)]
Time = [0 for i in range(idx)]
int_to_name = {j:i for i,j in name_to_int.items()}
gang = [[] for i in range(idx)]
gang_cnt = 0
cur = 0
def dfs(s,gang_cnt):
    global vis,gang,Time,cur
    if vis[s]:
        return
    vis[s] = True
    gang[gang_cnt].append(s)
    for each in g[s]:
        cur += each[1]
        Time[s] += each[1]
        Time[each[0]] += each[1]
        dfs(each[0],gang_cnt)
ans = []
for i in range(idx):
    if vis[i] == False:
        gang_cnt += 1
        cur = 0
        dfs(i,gang_cnt)
        if len(gang[gang_cnt]) > 2 and cur > k:
            ans.append(gang_cnt)
print(len(ans))
head =[]
for each in ans:
    cur = 0
    who = -1
    for one in gang[each]:
        if Time[one] > cur:
            cur = Time[one]
            who = one
    head.append((int_to_name[who],len(gang[each])))
head.sort(key=lambda x:x[0])
for each in head:
    print("{} {}".format(each[0],each[1]))