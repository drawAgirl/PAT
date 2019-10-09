from fractions import Fraction
n = int(input())
data = list(input().split())
ans = Fraction(0)
for each in data:
    ans += Fraction(each)
if ans.numerator > ans.denominator and ans.numerator % ans.denominator != 0:
    print("%d %d/%d"%(ans.numerator//ans.denominator,ans.numerator%ans.denominator,ans.denominator))
else:
    print(ans)