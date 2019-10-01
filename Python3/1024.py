def check(n):
    for i in range(len(n)//2):
        if n[i] != n[len(n)-i-1]:
            return False
    return True

n,k=input().split()
k=int(k)
flag = False
i = 1
if check(n):
    print(n)
    print("0")
else:
    while i<=k:
        reverse_num = n[::-1]
        temp =int(reverse_num) + int(n)
        new_t = str(temp)
        if check(str(new_t)):
            flag = True
            break
        i += 1
        n = new_t
    print(temp)
    if flag == False:
        i -=1
    print(i)