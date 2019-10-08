from queue import Queue
n,g = map(int,input().split())
ans = [0 for i in range(n)]
w = list(map(int,input().split()))
q = Queue()
other = Queue()
permutation = list(map(int,input().split()))
for each in permutation:
    q.put(each)
while q.qsize() != 1:
    now_max = -1
    now_idx = -1
    times = q.qsize()//g
    rest = q.qsize()%g
    rank = times+1
    if rest:
        rank +=1
    while times:
        times -= 1
        for _ in range(g):
            cur = q.get()
            other.put(cur)
            if w[cur] > now_max:
                now_max = w[cur]
                now_idx = cur
        q.put(now_idx)
        while other.qsize():
            cur = other.get()
            if cur == now_idx:
                continue
            ans[cur] = rank
        now_idx = -1
        now_max = -1
    if rest != 0:
        while rest:
            rest -=1
            cur = q.get()
            other.put(cur)
            if w[cur] > now_max:
                now_max = w[cur]
                now_idx = cur
        q.put(now_idx)
        while other.qsize():
            cur = other.get()
            if cur == now_idx:
                continue
            ans[cur] = rank
ans[q.get()] = 1
for i in range(len(ans)):
    print(ans[i],end='')
    if i != len(ans)-1:
        print(" ",end='')
