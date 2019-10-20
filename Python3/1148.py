n=int(input())
arr = [None]
for _ in range(n):
    num = int(input())
    arr.append(num)
flag = False
for i in range(1,n):
    for j in range(i+1,n+1):
        liar = []
        a = [1 for i in range(n+1)]
        a[i] = a[j] = -1
        for k in range(1,n+1):
            if arr[k] * a[abs(arr[k])] < 0:
                liar.append(k)
        if len(liar) == 2 and a[liar[0]] + a[liar[1]] == 0:
            print(i,j)
            flag = True
            break
    if flag:
        break
if flag == False:
    print("No Solution")