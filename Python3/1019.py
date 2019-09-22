n,base=map(int,input().split())
arr = []
while n != 0:
    arr.append(n % base)
    n = n // base
flag = True
for i in range(len(arr)//2):
    if arr[i] != arr[len(arr)-1-i]:
        flag = False
        break
if flag:
    print("Yes")
else:
    print("No")
for i in range(len(arr)-1,-1,-1):
    print("%d"%arr[i],end="")
    if i != 0:
        print(" ",end="")