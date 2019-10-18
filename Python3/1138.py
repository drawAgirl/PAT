n = int(input())
PRE = list(map(int,input().split()))
IN = list(map(int,input().split()))
post = []

def printpostorder(inorder, preorder, n):
    if len(post):
        return
    if preorder[0] in inorder:
        root = inorder.index(preorder[0])
    if root != 0:  # left subtree exists
        printpostorder(inorder[:root],
                       preorder[1:root + 1],
                       len(inorder[:root]))

    if root != n - 1:  # right subtree exists
        printpostorder(inorder[root + 1:],
                       preorder[root + 1:],
                       len(inorder[root + 1:]))
    post.append(preorder[0])
printpostorder(IN,PRE,n)
print(post[0])