a,*b = map(eval,input().split())
c,*d = map(eval,input().split())
dic = {}
ans = {}
for i in range(0,len(b),2):
    dic[b[i]] = b[i+1]
for i in range(0,len(d),2):
    for key,value in dic.items():
        ans[key+d[i]] = ans.get(key+d[i],0)+value*d[i+1]
        if(ans[key+d[i]] == 0):
            del ans[key+d[i]]

ans = sorted(ans.items(),key=lambda x:x[0],reverse=True)
print(len(ans),end='')
for x,y in ans:
    print(" {} {:.1f}".format(x, y), end="")