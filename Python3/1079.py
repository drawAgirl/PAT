n,p,r = map(eval,input().split())
r = r / 100
son = {}
weight = {}
for i in range(n):
    a,*b = map(int,input().split())
    if a == 0:
        weight[i] = b[0]
    else:
        son[i] = b
global ans
ans = 0.0
def dfs(root,depth):
    if weight.get(root) != None: #这里查找weight也可以，就是为了找到叶子结点停止,应该Wweight快一点
        global ans
        ans = ans + p*pow(1+r,depth)*weight[root]
        return
    for each in son[root]:
        dfs(each,depth+1)
dfs(0,0)
print("%.1f"%ans)
