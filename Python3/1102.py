from queue import Queue
n = int(input())
lchild = {}
rchild = {}
def level(root):
    q = Queue()
    q.put(root)
    space = 0
    while q.qsize():
        size = q.qsize()
        while size:
            size = size -1
            space = space+1
            temp = q.get()
            print("%d"%temp,end='')
            if space != n:
                print(" ",end='')
            if lchild.get(temp) != None:
                q.put(lchild[temp])
            if rchild.get(temp) != None:
                q.put(rchild[temp])
    print()
global space
space = 0

def inorder(root):
    if lchild.get(root) != None:
        inorder(lchild[root])
    print("%d"%root,end='')
    global space
    space = space + 1
    if space != n:
        print(" ",end='')
    if rchild.get(root) != None:
        inorder(rchild[root])
flag = [i for i in range(n)]
for i in range(n):
    a,b = input().split()
    if a != '-':
        a = eval(a)
        rchild[i] = a
        flag[a] = -1
    if b != '-':
        b = eval(b)
        lchild[i] = b
        flag[b] = -1
for each in flag:
    if each != -1:
        root = each
        break
level(root)
inorder(root)