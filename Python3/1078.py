Prime = [False for i in range(10010)]
Hash = Prime.copy()
for i in range(2,10010):
    if Prime[i] == False:
        for j in range(i+i,10010,i):
            Prime[j] = True
m,n = map(int,input().split())
if m<=1:
    m=2
while Prime[m]:
    m += 1
data = list(map(int,input().split()))
for i in range(len(data)):
    now = data[i]%m
    j = 0
    while j<=m:
        location = (now+j*j)%m
        if Hash[location] == False:
            Hash[location] = True
            print(location,end='')
            break
        j += 1
    if j==m+1:
        print("-",end='')
    if i != len(data)-1:
        print(" ",end='')