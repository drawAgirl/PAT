n = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
dp = [[0 for i in range(B[0]+1)] for j in range(A[0]+1)]
for i in range(1,A[0]+1):
    for j in range(1,B[0]+1):
        MAX = max(dp[i-1][j],dp[i][j-1])
        if A[i] == B[j]:
            dp[i][j] = MAX +1
        else:
            dp[i][j] = MAX
print(dp[A[0]][B[0]])
