s = input()
length = len(s)
dp = [[0 for i in range(length)] for j in range(length)]
longest = 1
for i in range(length):
    dp[i][i] = 1
    if i < length-1:
        if s[i] == s[i+1]:
            dp[i][i+1] = 1
            start = i
            longest = 2
for l in range(3,length+1):
    i = 0
    while i+l-1 < length:
        j = l+i-1
        if s[i] == s[j] and dp[i+1][j-1] == 1:
            dp[i][j] = 1
            start = i
            longest = l
        i +=1
print(longest)