from queue import Queue
n,l = map(int,input().split())
g={i:[] for i in range(1,n+1)}
for i in range(1,n+1):
    _,*a=map(int,input().split())
    for each in a:
        g[each].append(i)
_,*queries = map(int,input().split())
for query in queries:
    vis = [False for i in range(n+1)]
    q = Queue()
    q.put(query)
    ans = -1
    cnt = 0
    while q.qsize() and cnt <= l:
        size = q.qsize()
        cnt += 1
        while size:
            size-=1
            cur = q.get()
            if vis[cur]:
                continue
            vis[cur] = True
            ans += 1
            for each in g[cur]:
                q.put(each)
    print(ans)


