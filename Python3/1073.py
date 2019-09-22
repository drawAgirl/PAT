a,b = input().split('E')
if a[0] == '-':
    print("-",end='');
b = int(b)
a=a[1:]
if b<0:
    print("0.",end='')
    for i in range(abs(b)-1):
        print("0",end='')
    for i in range(len(a)):
        if a[i] != '.':
            print("%c"%a[i],end='')
else:
    print("%c"%a[0],end='')
    cnt = 0
    j = 2
    while j<len(a) and cnt < b:
        print("%c"%a[j],end='')
        cnt = cnt +1
        j = j+1
    if j == len(a):
        for i in range(b-cnt):
            print("0",end='')
    else:
        print(".",end='')
        for i in range(j,len(a)):
            print(a[i],end='')
