from queue import Queue
n = int(input())
PostOrder = list(map(int,input().split()))
InOrder = list(map(int,input().split()))
class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
def build(inL,inR,postL,postR):
    if inL > inR:
        return None
    k = -1
    for i in range(inL,inR+1):
        if InOrder[i] == PostOrder[postR]:
            k = i
            break
    numleft = k-inL
    root = Node(PostOrder[postR])
    root.left = build(inL, k-1, postL, postL+numleft-1)
    root.right = build(k+1, inR, postL+numleft, postR-1)
    return root
def LevelOrder(root,n):
    q = Queue()
    q.put(root)
    while q.qsize():
        size = q.qsize()
        while size:
            size = size - 1
            n = n - 1
            temp = q.get()
            print("%d"%temp.data,end='')
            if n:
                print(" ",end='')
            if temp.left:
                q.put(temp.left)
            if temp.right:
                q.put(temp.right)
root = build(0,n-1,0,n-1)
LevelOrder(root,n)
