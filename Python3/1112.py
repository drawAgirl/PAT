k=int(input())
s = input()
dic = {}
i = 0
while i < len(s):
    p = i
    while p+1 < len(s) and s[p] == s[p+1]:
        p += 1
    cnt = p-i+1
    if cnt % k:
        dic[s[i]] = True
    else:
        if dic.get(s[i]) is None:
            dic[s[i]] = False
    i += cnt
broke=[]
ans=[]
add = {}
i = 0
while i < len(s):
    if dic[s[i]] == False:
        if add.get(s[i]) is None:
            add[s[i]] = True
            broke.append(s[i])
        p = i
        while p+1 <len(s) and s[p] == s[p+1]:
            p += 1
        cnt = p-i+1
        for j in range(cnt//k):
            ans.append(s[i])
        i += cnt
    else:
        cnt = 1
        ans.append(s[i])
        i += cnt
for each in broke:
    print(each,end='')
print()
for each in ans:
    print(each,end='')