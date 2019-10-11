from math import sqrt
n = int(input())
max_len = 0
index = -1
for i in range(2,int(sqrt(n))+1):
    base = 1
    j = i
    while True:
        base = base * j
        if n % base != 0:
            break
        if j-i+1 > max_len:
            max_len = j-i+1
            index = i
        j += 1
if max_len == 0:
    print("1")
    print(n)
else:
    print(max_len)
    for i in range(index,index+max_len):
        print(i,end='')
        if i != index+max_len-1:
            print("*",end='')
