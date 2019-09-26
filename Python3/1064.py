n = int(input())
number = list(map(int,input().split()))
number.sort()
ind = 0
arr = [i for i in range(n+1)]
def Inorder(root):
    global ind
    if root > n:
        return
    Inorder(2*root)
    arr[root] =number[ind]
    ind += 1
    Inorder(2*root+1)
Inorder(1)
for i in range(1,n+1):
    print("%d"%arr[i],end='')
    if i != n:
        print(" ",end='')
