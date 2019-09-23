n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
a.sort()
b.sort()
ans = 0
i = 0
while i<n and i<m and a[i]<0 and b[i] < 0:
    ans = ans + a[i]*b[i]
    i = i + 1
i = n-1
j = m-1
while i>=0 and j>=0 and a[i]>0 and b[j]>0:
    ans = ans + a[i]*b[j]
    i = i-1
    j = j-1
print("%d"%ans)