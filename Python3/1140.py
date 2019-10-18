d,n = input().split()
n=int(n)

for _ in range(1,n):
    ans = ""
    i = 0
    while i<len(d):
        k = i
        while k < len(d) and d[k] == d[i]:  k+=1
        ans += d[i]+str(k-i)
        if k == len(d): break
        i = k
    d = ans
print(d)
