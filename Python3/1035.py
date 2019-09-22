n = int(input())
ans = []
for _ in range(n):
    a,b = input().split()
    flag = True
    b = list(b)
    for i in range(len(b)):
        if b[i] == '1':
            flag = False
            b[i] = '@'
        elif b[i] == '0':
            flag = False
            b[i] = '%'
        elif b[i] == 'l':
            flag = False
            b[i] = 'L'
        elif b[i] == 'O':
            flag = False
            b[i] = 'o'
    if flag == False:
        b = ''.join(b)
        ans.append([a,b])
if len(ans) == 0:
    if n == 1:
        print("There is 1 account and no account is modified")
    else:
        print("There are %d accounts and no account is modified"%n)
else:
    print(len(ans))
    for item in ans:
        print("%s %s"%(item[0],item[1]))
