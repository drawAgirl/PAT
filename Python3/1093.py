data = str(input())
cnt = 0
d = {}
ans = 0
t = 0
for i in range(len(data)):
    d[i] = 0
for i,j in enumerate(data):
    if(data[i] == 'P'):
        cnt = cnt + 1
    d[i] = cnt
for i in range(len(data)-1,0,-1):
    if(data[i] == 'T'):
        t = t + 1
    elif data[i] == 'A':
        ans = ans + t*d[i]
    if (ans >= 1000000007):
        ans = ans % 1000000007
print(ans)