def swap(x,y,number):
    t = number[x]
    number[x] = number[y]
    number[y] = t
n,*number = map(int,input().split())
dic = {}
for i,j in enumerate(number):
    dic[j] = i
cnt = 0
base = 1
while True:
    zero = dic[0]
    while zero != 0:
        swap(zero,dic[zero],number)
        swap(0,zero,dic)
        zero = dic[0]
        cnt = cnt + 1
    flag = True
    var = 0
    for i in range(base,n):
        if dic[i] != i:
            flag = False
            var = i
            break
    if flag:
        print("%d"%cnt)
        break
    else:
        cnt = cnt +1
        base = var+1
        swap(var, dic[var], number)
        swap(0, var, dic)

