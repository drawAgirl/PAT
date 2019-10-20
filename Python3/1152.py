from math import sqrt
def isPrime(n):
    if n < 2:
        return False
    for i in range(2,int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True
l,k=map(int,input().split())
number = input()
flag = False
for i in range(l-k+1):
    num = int(number[i:k+i])
    if isPrime(num):
        print(number[i:k+i])
        flag = True
        break
if flag == False:
    print("404")