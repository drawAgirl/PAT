from functools import cmp_to_key
n,m,s = map(int,input().split())
weight = list(map(int,input().split()))
dic = {}
cur = []
ans = []
for _ in range(m):
    father,_,*son = map(int,input().split())
    dic[father] = son
def dfs(root,cnt,ans):
    if dic.get(root) == None and cnt - weight[root] == 0:
        cur.append(weight[root])
        new_cur = cur.copy() # list这些可变参数是直接引用的，所以如果直接apped下次cur.pop也会导致ans里的list改变
        ans.append(new_cur)
        cur.pop()
        return
    if dic.get(root) is None:
        return
    for each in dic[root]:
        cur.append(weight[root])
        dfs(each,cnt-weight[root],ans)
        cur.pop()
def mycmp(a,b):
    minlen = min(len(a),len(b))
    for i in range(minlen):
        if a[i] != b[i]:
            if a[i] > b[i]:
                return 1
            if a[i] < b[i]:
                return -1
    if len(a) > len(b):
        return 1
    if len(a) < len(b):
        return -1
    return 0

dfs(0,s,ans)
ans.sort(key=cmp_to_key(mycmp),reverse=True)
for each in ans:
    for i in range(len(each)):
        print(each[i],end='')
        if i != len(each)-1:
            print(" ",end='')
    print()