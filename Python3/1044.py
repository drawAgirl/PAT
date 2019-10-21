def upper_bound(l,r,x):
    global arr
    while l < r:
        mid = (l+r) >> 1
        if arr[mid] > x:
            r = mid
        else:
            l = mid+1
    return l
n,m = map(int,input().split())
number = list(map(int,input().split()))
arr=[0]
for i in range(n):
    arr.append(arr[i]+number[i])
ans = 1e6
for i in range(1,n+1):
    j = upper_bound(i,n+1,arr[i-1]+m)
    if arr[j-1] - arr[i-1] == m:
        ans = m
        break
    if j <= n and arr[j-1]-arr[i-1] < ans:
        ans = arr[j]-arr[i-1]
for i in range(1,n+1):
    j = upper_bound(i,n+1,arr[i-1]+ans)
    if arr[j-1] - arr[i-1] == ans:
        print("%d-%d"%(i,j-1))
