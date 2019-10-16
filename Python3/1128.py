n=int(input())

for _ in range(n):
    flag = True
    _,*data = map(int,input().split())
    for i in range(len(data)):
        for j in range(1,len(data)-i):
            if  data[i]-j == data[i+j] or data[i] == data[i+j]:
                flag = False
                break
    if flag:    print("YES")
    else:   print("NO")