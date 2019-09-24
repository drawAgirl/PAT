from operator import itemgetter
dic = {}
after = {}
n,head = map(int,input().split())
for _ in range(n):
    a,b,c = map(int,input().split())
    dic[a] = [b,c]  # B排序
while head != -1:
    after[head] = dic[head]
    head = dic[head][1]
if len(after) == 0:
    print("0 -1")
else:
    ans = sorted(after.items(),key=itemgetter(1,0))
    print("%d %05d"%(len(after),ans[0][0]))
    for i in range(len(ans)):
        if i != len(ans)-1:
            print("%05d %d %05d"%(ans[i][0],ans[i][1][0],ans[i+1][0]))
        else:
            print("%05d %d -1" % (ans[i][0], ans[i][1][0]))

