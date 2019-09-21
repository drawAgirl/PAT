a,*b = map(eval,input().split())
c,*d = map(eval,input().split())
dic = {}

for i in range(0,len(b),2):
    dic[b[i]] = b[i+1]
for i in range(0,len(d),2):
    dic[d[i]] = dic.get(d[i],0)+d[i+1]
    if dic[d[i]] == 0:
        del dic[d[i]]
dic=sorted(dic.items(),key=lambda x:x[0],reverse=True)
print(len(dic),end="")
for x,y in dic:
    print(" {} {:.1f}".format(x,y),end="")