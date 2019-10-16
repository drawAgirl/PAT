class node:
    def __init__(self,val,left=None,right=None):
        self.val = val
        self.left = left
        self.right = right
n=int(input())
tree = {i:None for i in range(1,n+1)}
tree[-1] = node(-1,-1,-1)
isRoot = [False for i in range(n+1)]
for i in range(1,n+1):
    a,b,c = input().split()
    b = int(b)
    c = int(c)
    tree[i] = node(a,b,c)
    if b != -1:
        isRoot[b] = True
    if c != -1:
        isRoot[c] = True
ROOT = isRoot.index(False,1)
def dfs(root):
    global ROOT
    if root == -1:
        return
    flag = False
    if root != ROOT and (tree[root].left != -1 or tree[root].right != -1):
        flag = True
        print("(",end='')
    dfs(tree[root].left)
    print(tree[root].val,end='')
    dfs(tree[root].right)
    if flag:
        print(")",end='')
dfs(ROOT)