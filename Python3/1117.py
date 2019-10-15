n=int(input())
number = list(map(int,input().split()))
number.append(-1)
number.sort()
ans = 0
for i in range(1,n+2):
    if number[n-i+1] > i:
        ans = i
print(ans)