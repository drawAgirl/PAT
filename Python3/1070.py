n,m = map(float,input().split())
cakes = list(map(float,input().split()))
total = list(map(float,input().split()))
price = []
for i in range(int(n)):
    single = total[i]/cakes[i]
    price.append([single,i])
price.sort(key=lambda x:x[0],reverse=True)
ans = 0.0
for each in price:
    if m <= 0:
        break
    if cakes[each[1]] >= m:
        ans = ans + each[0]*m
    else:
        ans = ans + cakes[each[1]]*each[0]
    m = m - cakes[each[1]]
print("%.2f"%ans)

