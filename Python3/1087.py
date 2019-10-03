n,m,start = input().split()
n = int(n)
dic = {start:0}
happy = [0]
d = [1e6 for i in range(n)]
vis = [False for i in range(n)]
g = {i:[] for i in range(n)}
pre = [[] for i in range(n)]
temppath=[]
path = []
cnt = 0
max_happy = 0
max_average = 0
for i in range(1,n):
    city,haha = input().split()
    dic[city] = i
    happy.append(int(haha))
for i in range(int(m)):
    c1,c2,dis = input().split()
    g[dic[c1]].append((int(dis),dic[c2]))
    g[dic[c2]].append((int(dis),dic[c1]))
from queue import PriorityQueue
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
            d[to] = dis+cur[0]
            pre[to].clear()
            pre[to].append(cur[1])
            q.put((d[to],to))
        elif vis[to] == False and dis +cur[0] == d[to]:
            pre[to].append(cur[1])
            q.put((d[to],to))
def dfs(s):
    global cnt,temppath,path,max_happy,max_average
    if s == 0:
        cnt += 1
        total = 0
        for each in temppath:
            total += happy[each]
        average = total/len(temppath)
        if total > max_happy:
            max_happy = total
            max_average = average
            path = temppath.copy()
        elif total == max_happy and average > max_average:
            max_average = average
            path = temppath.copy()
        return
    temppath.append(s)
    for each in pre[s]:
        dfs(each)
    temppath.pop()
dfs(dic['ROM'])
path.append(0)
print("%d %d %d %d"%(cnt,d[dic['ROM']],max_happy,max_average))
back_to_str = dict(zip(dic.values(),dic.keys()))
for each in path[::-1]:
    print(back_to_str[each],end='')
    if each != path[0]:
        print("->",end='')