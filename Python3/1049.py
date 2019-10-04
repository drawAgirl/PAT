n=int(input())
a = 1
ans = 0
while n//a != 0:
    left = n//(10*a)
    now = n//a %10
    right = n%a
    if now == 0:
        ans += left*a
    elif now == 1:
        ans += left*a + right +1
    else:
        ans += (left+1)*a
    a = a*10
print(ans)