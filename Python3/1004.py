n,m = map(int,input().split())
tree = {}
for _ in range(m):
    father,_,*son = map(int,input().split())
    tree[father] = son
from queue import Queue
q = Queue()
q.put(1)
level = []
while q.qsize():
    cnt = 0
    size = q.qsize()
    while size:
        size -= 1
        temp = q.get()
        if tree.get(temp) is None:
            cnt += 1
        else:
            for each in tree[temp]:
                q.put(each)
    level.append(cnt)
for i in range(len(level)):
    print("%d"%level[i],end='')
    if i != len(level)-1:
        print(" ",end='')