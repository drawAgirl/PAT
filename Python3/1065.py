n = int(input())
for i in range(1,1+n):
    a,b,c = map(int,input().split())
    if(a + b > c):
        print("Case #%d: true"%i)
    else:
        print("Case #%d: false"%i)