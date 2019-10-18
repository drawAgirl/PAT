from math import sqrt
def isPrime(n):
    if n < 2:
        return False
    for i in range(2,int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True
Msize,n,m = map(int,input().split())
number = list(map(int,input().split()))
query = list(map(int,input().split()))
cnt = 0
while isPrime(Msize) == False:
    Msize += 1
HASH = [-1 for i in range(Msize)]
for key in number:
    flag = True
    for i in range(Msize):
        location = (key + i*i) % Msize
        if HASH[location] == -1:
            HASH[location] = key
            flag = False
            break
    if flag:
        print("%d cannot be inserted."%key)
for key in query:
    for i in range(Msize+1):
        cnt+=1
        location = (key + i*i) % Msize
        if HASH[location] == -1 or HASH[location] == key:
            break
print("%.1f"%(cnt/m))


