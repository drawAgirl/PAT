n,m = map(int,input().split())
tree = {}
for _ in range(m):
    father,_,*son = map(int,input().split())
    tree[father] = son
level = 0
ans = 0
cnt = 0
from queue import Queue
q = Queue()
q.put(1)
while q.qsize():
    size = q.qsize()
    cnt += 1
    if size > ans:
        ans = size
        level = cnt
    while size:
        size -= 1
        temp = q.get()
        if tree.get(temp) != None:
            for each in tree[temp]:
                q.put(each)
print("%d %d"%(ans,level))