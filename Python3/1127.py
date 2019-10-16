from queue import Queue
n=int(input())
Inorder = list(map(int,input().split()))
Postorder = list(map(int,input().split()))
class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
def construct(inl,inr,postl,postr):
    if inl > inr:
        return None
    k = Inorder.index(Postorder[postr])
    root = node(Postorder[postr])
    numleft = k-inl
    root.left = construct(inl,inl+numleft-1,postl,postl+numleft-1)
    root.right = construct(k+1,inr,postl+numleft,postr-1)
    return root
root = construct(0,n-1,0,n-1)
q = Queue()
q.put(root)
flag = 1
space = 0
while q.qsize():
    size = q.qsize()
    now = []
    while size:
        size -= 1
        cur = q.get()
        now.append(cur.val)
        if cur.left:
            q.put(cur.left)
        if cur.right:
            q.put(cur.right)
    if flag == -1:
        for each in now:
            space += 1
            print(each,end='')
            if space != n:  print(' ',end='')
    else:
        for each in now[::-1]:
            space += 1
            print(each,end='')
            if space != n:  print(' ',end='')
    flag *= -1
