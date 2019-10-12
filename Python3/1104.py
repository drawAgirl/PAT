n=int(input())
num = list(map(eval,input().split()))
ans = 0
for i in range(n):
    ans += num[i]*(i+1)*(n-i)
print("{:.2f}".format(ans))