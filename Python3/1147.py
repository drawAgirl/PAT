m,n = map(int,input().split())

def isMax(tree):
    for i in range(1,n//2+1):
        if 2*i <=n:
            if tree[i] < tree[2*i]:
                return False
        if 2*i+1 <=n:
            if tree[i] < tree[2*i+1]:
                return False
    return True

def isMin(tree):
    for i in range(1,n//2+1):
        if 2*i <= n:
            if tree[i] > tree[2*i]:
                return False
        if 2*i+1 <=n:
            if tree[i] > tree[2*i+1]:
                return False
    return True

def Postorder(root):
    global post
    if root > n:
        return
    Postorder(2*root)
    Postorder(2*root+1)
    post.append(tree[root])


for _ in range(m):
    tree = list(map(int,input().split()))
    tree.insert(0,0)
    post = []
    if isMax(tree) == True:
        print("Max Heap")
    elif isMin(tree) == True:
        print("Min Heap")
    else:
        print("Not Heap")
    Postorder(1)
    for i in range(n):
        print(post[i],end='')
        if i != n-1:
            print(" ",end='')
        else:
            print()