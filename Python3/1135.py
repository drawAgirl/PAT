from functools import reduce
k = int(input())
class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None


def insert(root,val):
    if root is None:
        root = node(val)
        return root
    if abs(root.val) < abs(val):
        root.right = insert(root.right,val)
    else:
        root.left = insert(root.left,val)
    return root

def dfs(root,cnt):
    global black,flag
    iscnt = False
    if root is None:
        if black == -1:
            black = cnt
        if black != cnt:
            flag = False
        return
    if root.val < 0:
        if root.left is not None and root.left.val < 0:
            flag = False
        if root.right is not None and root.right.val < 0:
            flag = False
        if flag == False:
            return
    else:
        iscnt = True
        cnt += 1
    dfs(root.left,cnt)
    dfs(root.right,cnt)
    if iscnt:
        cnt -= 1

for _ in range(k):
    n = int(input())
    number = list(map(int,input().split()))
    if number[0] < 0:
        print("No")
        continue
    root = None
    for val in number:
        root = insert(root,val)
    flag = True
    black = -1
    dfs(root,0)
    if flag:
        print("Yes")
    else:
        print("No")