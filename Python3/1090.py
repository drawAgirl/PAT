n,p,r = map(eval,input().split())
r /= 100
data = list(map(int,input().split()))
tree = {}
for i in range(n):
    if tree.get(data[i]) is None:
        tree[data[i]] = [i]
    else:
        tree[data[i]].append(i)
    if data[i] == -1:
        root = i
        del tree[-1]
cnt = 0
ans = 0.0
def dfs(root,depth):
    global cnt,ans
    if tree.get(root) is None:
        temp = p*pow(1+r,depth)
        if temp > ans:
            ans = temp
            cnt = 1
        elif temp == ans:
            cnt += 1
        return
    for each in tree[root]:
        dfs(each,depth+1)
dfs(root,0)
print("%.2f %d"%(ans,cnt))