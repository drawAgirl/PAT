class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
m,n = map(int,input().split())
Inorder = list(map(int,input().split()))
Preorder = list(map(int,input().split()))
dic = {}
def Construct(inL,inR,preL,preR):
    global Inorder,Preorder
    if inL > inR:
        return
    k = -1
    for i in range(inL,inR+1):
        if Inorder[i] == Preorder[preL]:
            dic[Preorder[preL]] = True
            k = i
            break
    root = node(Preorder[preL])
    numleft = k - inL
    root.left = Construct(inL,k-1,preL+1,preL+numleft)
    root.right = Construct(k+1,inR,preL+numleft+1,preR)
    return root
def LCA(root,a,b):
    if root is None:
        return None
    if root.val == a or root.val == b:
        return root
    left = LCA(root.left,a,b)
    right = LCA(root.right,a,b)
    if left != None and right != None:
        return root
    if left is None:
        return right
    else:
        return left

root = Construct(0,n-1,0,n-1)
for _ in range(m):
    a,b = map(int,input().split())
    if dic.get(a) is None and dic.get(b) is None:
        print("ERROR: %d and %d are not found."% (a,b))
    elif dic.get(a) is None:
        print("ERROR: %d is not found."%a)
    elif dic.get(b) is None:
        print("ERROR: %d is not found."%b)
    else:
        cur = LCA(root,a,b)
        if cur.val == a:
            print("%d is an ancestor of %d."% (a, b))
        elif cur.val == b:
            print("%d is an ancestor of %d."% (b, a))
        else:
            print("LCA of %d and %d is %d."%(a,b,cur.val))