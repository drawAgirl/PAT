n,m = map(int,input().split())
dic = {}
cnt = 0
for _ in range(m):
    num = list(map(int,input().split()))
    for each in num:
        if dic.get(each) is None:
            dic[each] = 0
        dic[each] += 1
        if dic[each] > cnt:
            cnt = dic[each]
            ans = each
print(ans)