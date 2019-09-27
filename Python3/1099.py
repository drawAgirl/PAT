n = int(input())
tree = {}
for i in range(n):
    left,right = map(int,input().split())
    tree[i] = [left,right]
data = list(map(int,input().split()))
data.sort()
ind = 0
def Inorder(root):
    global ind
    if tree[root][0] != -1:
        Inorder(tree[root][0])
    tree[root].append(data[ind])
    ind += 1
    if tree[root][1] != -1:
        Inorder(tree[root][1])
Inorder(0)
from queue import Queue
q = Queue()
q.put(0)
space = 0
while q.qsize():
    size = q.qsize()
    while size:
        size -= 1
        temp  = q.get()
        print("%d"%tree[temp][-1],end='')
        space += 1
        if space != n:
            print(" ",end='')
        if tree[temp][0] != -1:
            q.put(tree[temp][0])
        if tree[temp][1] != -1:
            q.put(tree[temp][1])