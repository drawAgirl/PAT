head,n,k = map(int,input().split())
data = {}
next = {}
result = []
for _ in range(n):
    a,b,c = map(int,input().split())
    data[a] = b
    next[a] = c
while head != -1:
    result.append(head)
    head = next[head]
ans = result.copy()
for i in range(len(result)-len(result)%k):
    ans[i] = result[i // k * k + k - 1 - i % k]
for i in range(len(result)-1):
    print("%05d %d %05d"%(ans[i], data[ans[i]], ans[i + 1]))
print("%05d %d -1"%(ans[-1],data[ans[-1]]))
