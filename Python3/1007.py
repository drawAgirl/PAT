n = int(input())
arr = list(map(int,input().split()))
dp = [arr[0]]
ind = [0]
flag = False if arr[0]>=0 else True
for i in range(1,len(arr)):
    if arr[i] >= 0:
        flag = False
    temp = arr[i] + dp[i-1]
    if temp > arr[i]:
        dp.append(temp)
        ind.append(ind[i-1])
    else:
        dp.append(arr[i])
        ind.append(i)
if flag:
    print("0 {} {}".format(arr[0],arr[-1]))
else:
    k = 0
    for i in range(1,len(dp)):
        if dp[i] > dp[k]:
            k = i
    print("{} {} {}".format(dp[k],arr[ind[k]],arr[k]))