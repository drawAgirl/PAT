n=int(input())
vis = [False for i in range(n+1)] #多加一个位置给后面 VIS[-1]留位置
arr = [None for i in range(50)]
tree = []
root = -1
def dfs(index,root):
    if index > n:
        return
    arr[index] = root
    if root == -1:
        return
    dfs(2*index,tree[root].left)
    dfs(2*index+1,tree[root].right)
class node:
    def __init__(self,left,right):
        self.left = left
        self.right = right
def to_int(n):
    if n == "-":
        return -1
    return int(n)
for i in range(n):
    a,b = input().split()
    a = to_int(a)
    b = to_int(b)
    vis[a] = vis[b] = True
    tree.append(node(a,b))
for i in range(n):
    if vis[i] == False:
        root = i
        break
dfs(1,root)
flag = True
last = -1
for i in range(1,n+1):
    if arr[i] == -1:
        flag = False
        break
    last = arr[i]
if flag:
    print("YES %d"%last)
else:
    print("NO %d"%root)