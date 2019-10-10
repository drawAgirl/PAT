n=int(input())
first = list(map(int,input().split()))
last = list(map(int,input().split()))
back_up = first.copy()
def show(a):
    for i in range(n):
        print(a[i],end='')
        if i != n-1:
            print(" ",end='')
def merge(a,l1,r1,l2,r2):
    i= l1
    j = l2
    ans = [0 for i in range(n)]
    index = 0
    while i<=r1 and j<=r2:
        if a[i]<=a[j]:
            ans[index] = a[i]
            i+=1
        else:
            ans[index] = a[j]
            j+=1
        index += 1
    while i<=r1:
        ans[index] = a[i]
        i +=1
        index += 1
    while j<=r2:
        ans[index] = a[j]
        j +=1
        index +=1
    for i in range(index):
        a[l1+i] = ans[i]
flag_2 = False
def sort(a):
    global flag_2
    step = 2
    while step//2 <= n:
        for i in range(0,n,step):
            mid = i + step//2 - 1
            if mid+1<=n:
                merge(a,i,mid,mid+1,min(i+step-1,n-1))
        if flag_2:
            show(a)
            break
        if a == last:
            flag_2 = True
        step = step*2
flag = False
for i in range(1,n):
    temp = first[i]
    j = i
    while j>0 and temp < first[j-1]:
        first[j] = first[j-1]
        j -= 1
    first[j] = temp
    if flag:
        print('Insertion Sort')
        show(first)
        break
    if first==last:
        flag = True
if flag is False:
    print("Merge Sort")
    sort(back_up)