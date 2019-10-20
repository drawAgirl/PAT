n = int(input())
heap = list(map(int,input().split()))
heap.insert(0,0)
path = []
def dfs(root):
    global path
    if root > n:
        return
    path.append(heap[root])
    if 2*root > n:
        for i in range(len(path)):
            print("%d"%path[i],end='')
            if i != len(path)-1:
                print(' ',end='')
            else:
                print('')
        path.pop()
        return
    dfs(2*root+1)
    dfs(2*root)
    path.pop()
def isMax():
    for i in range(1,n//2+1):
        if heap[i] < heap[2*i]:
            return False
        if 2*i+1 <= n and heap[i] < heap[2*i+1]:
            return False
    return True
def isMin():
    for i in range(1,n//2+1):
        if heap[i] > heap[2*i]:
            return False
        if 2*i+1 <=n and heap[i] > heap[2*i+1]:
            return False
    return True
dfs(1)
if isMax():
    print("Max Heap")
elif isMin():
    print("Min Heap")
else:
    print("Not Heap")