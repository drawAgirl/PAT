n = int(input())
arr = [0]+list(map(int,input().split()))
heap = arr.copy()
result = [0]+list(map(int,input().split()))
def Downadjust(low,high):
    i = low
    j = 2*i
    while j<=high:
        if j+1<=high and heap[j+1] > heap[j]:
            j+=1
        if heap[j] > heap[i]:
            temp = heap[j]
            heap[j] = heap[i]
            heap[i] = temp
            i = j
            j = 2*i
        else:
            break
def Createheap():
    for i in range(n//2,0,-1):
        Downadjust(i,n)
def show(a):
    for i in range(1,n+1):
        print(a[i],end='')
        if i != n:
            print(" ",end='')
flag = False
for i in range(2,n+1):
    key = arr[i]
    j = i-1
    while j>=1 and key < arr[j]:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key
    if flag:
        print("Insertion Sort")
        show(arr)
        break
    if arr == result:
        flag = True
if flag == False:
    print("Heap Sort")
    Createheap()
    for i in range(n,0,-1):
        temp = heap[i]
        heap[i] = heap[1]
        heap[1] = temp
        Downadjust(1,i-1)
        if flag:
            show(heap)
            break
        if heap == result:
            flag = True