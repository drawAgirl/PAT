n,*data = map(int,input().split())
pre = 0
time = 5*n
for each in data:
    if each > pre:
        time += 6*(each-pre)
        pre = each
    else:
        time += 4*(pre-each)
        pre = each
print("%d"%time)
