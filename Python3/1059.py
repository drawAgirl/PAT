from math import sqrt
MAXN = 100010
n = int(input())
prime = []
fac = []
flag = [False for i in range(MAXN)]
def find_prime():
    for i in range(2,MAXN):
        if flag[i] == False:
            prime.append(i)
            for j in range(2*i,MAXN,i):
                flag[i] = True
find_prime()
if n == 1:
    print("1=1")
else:
    print("%d="%n,end='')
    sqr = int(sqrt(n))
    for i in range(len(prime)):
        if prime[i] > sqr:
            break
        if n % prime[i] == 0:
            factor = prime[i]
            cnt = 0
            while n % prime[i] == 0:
                cnt += 1
                n = n//prime[i]
            fac.append((factor,cnt))
        if n== 1:
            break
    if n != 1:
        fac.append((n,1))
    for each in fac:
        if each != fac[0]:
            print("*",end='')
        print("%d"%each[0],end='')
        if each[1] > 1:
            print("^%d"%each[1],end='')