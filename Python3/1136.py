def isPali(n):
    for i in range(len(n)//2):
        if n[i] != n[len(n)-i-1]:
            return False
    return True
n = input()
flag = True
for i in range(10):
    if isPali(n):
        print("{} is a palindromic number.".format(n))
        flag = False
        break
    print("{} + {} = {}".format(n,n[::-1],int(n)+int(n[::-1])))
    n = str(int(n)+int(n[::-1]))
if flag:
    print("Not found in 10 iterations.")