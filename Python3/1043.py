class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def insert(root,data):
    if root is None:
        root = Node(data)
        return root
    if data < root.data:
        root.left = insert(root.left,data)
    else:
        root.right = insert(root.right,data)
    return root

def Pre_order(root):
    if root is None:
        return
    pre.append(root.data)
    Pre_order(root.left)
    Pre_order(root.right)

def Pre_order_mirror(root):
    if root is None:
        return
    pre_mirror.append(root.data)
    Pre_order_mirror(root.right)
    Pre_order_mirror(root.left)


def show(arr):
    for i in range(len(arr)):
        print("%d"%arr[i],end='')
        if i != len(arr)-1:
            print(" ",end='')
def Post_order(root):
    if root is None:
        return
    Post_order(root.left)
    Post_order(root.right)
    post.append(root.data)

def Post_order_mirror(root):
    if root is None:
        return
    Post_order_mirror(root.right)
    Post_order_mirror(root.left)
    post_mirror.append(root.data)
pre = []
pre_mirror=[]
post = []
post_mirror = []
n = int(input())
origin = list(map(int,input().split()))
root = Node(origin[0])

for each in origin[1:]:
    root = insert(root,each)
Pre_order(root)
# print(pre)
if pre == origin:
    print("YES")
    Post_order(root)
    show(post)
else:
    Pre_order_mirror(root)
    if pre_mirror == origin:
        print("YES")
        Post_order_mirror(root)
        show(post_mirror)
    else:
        print("NO")
