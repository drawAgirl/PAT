n=int(input())
num = list(map(int,input().split()))
max_num = [-1]
min_num = [1e9 for i in range(n)]
ans = []
for i in range(1,n):
    max_num.append(max(max_num[i-1],num[i-1]))
for i in range(n-2,-1,-1):
    min_num[i] = min(min_num[i+1],num[i+1])
for i in range(n):
    if num[i]>= max_num[i] and num[i] <= min_num[i]:
        ans.append(num[i])
print(len(ans))
for i in range(len(ans)):
    print(ans[i],end='')
    if i != len(ans)-1:
        print(" ",end='')
print()