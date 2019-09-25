n = int(input())
InOrder = []
PostOrder = []
num = []
for i in range(2*n):
    a,*b = input().split()
    if len(b):
        num.append(int(b[0]))
        InOrder.append(int(b[0]))
    else:
        t = num.pop()
        PostOrder.append(t)

class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
def build(inL,inR,preL,preR):
    if inL > inR:
        return None
    k = -1
    for i in range(preL,preR+1):
        if PostOrder[i] == InOrder[inL]:
            k = i
            break
    numleft = k - preL
    root = Node(InOrder[inL])
    root.left = build(inL+1, inL+numleft, preL, preL+numleft-1)
    root.right = build(inL+numleft+1, inR, preL+numleft+1, preR)
    return root
ans = []

def Post(root):
    if root is None:
        return
    Post(root.left)
    Post(root.right)
    ans.append(root.data)

root = build(0,n-1,0,n-1)
Post(root)
for i in range(len(ans)):
    print("%d"%ans[i],end='')
    if i != len(ans)-1:
        print(" ",end='')