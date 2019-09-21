a = list(map(eval,input().split()))
b = list(map(eval,input().split()))
c = list(map(eval,input().split()))
s = ['W','T','L']
profit = (max(a)*max(b)*max(c)*0.65-1)*2
print(s[a.index(max(a))],s[b.index(max(b))],s[c.index(max(c))],end=' ')
print("%.2f"%profit)