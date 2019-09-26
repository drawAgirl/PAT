n,p,r = map(eval,input().split())
r /= 100
tree = {}
for i in range(n):
    a,*b = map(int,input().split())
    if a == 0:
        continue
    tree[i] = b;

min_depth = 10000000
cnt = 1
def dfs(root,depth):
    global cnt,min_depth
    if tree.get(root) is None:
        if min_depth > depth:
            cnt = 1
            min_depth = depth
        elif min_depth == depth:
            cnt += 1
        return
    for each in tree[root]:
        dfs(each,depth+1)
dfs(0,0)
print("%.4f %d"%(p*pow(1+r,min_depth),cnt))