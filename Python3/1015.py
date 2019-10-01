from math import sqrt
def isPrimer(n):
    if n <= 1:
        return False
    for i in range(2,int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True
def convert(n,radix):
    data =[]
    while n!=0:
        t = n % radix
        n = n//radix
        data.append(t)
    ans = sum(j*pow(radix,i) for i,j in enumerate(data[::-1]))
    return  ans
while True:
    a = list(map(int,input().split()))
    if a[0] < 0:
        break
    if isPrimer(a[0]):
        if isPrimer(convert(a[0],a[1])):
            print("Yes")
        else:
            print("No")
    else:
        print("No")
