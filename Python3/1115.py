from queue import Queue
class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
def insert(root,val):
    if root is None:
        root = node(val)
        return root
    if root.val < val:
        root.right = insert(root.right,val)
    else:
        root.left = insert(root.left,val)
    return root
n=int(input())
number = list(map(int,input().split()))
root = None
for num in number:
    root = insert(root,num)
q = Queue()
q.put(root)
level = []
while q.qsize():
    size = q.qsize()
    level.append(size)
    while size:
        size -= 1
        cur = q.get()
        if cur.left:
            q.put(cur.left)
        if cur.right:
            q.put(cur.right)
print("%d + %d = %d"%(level[-1],level[-2],level[-1]+level[-2]))