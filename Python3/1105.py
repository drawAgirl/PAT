from math import sqrt
N=int(input())
arr = list(map(int,input().split()))
if N == 1:
    print(arr[0])
else:
    arr.sort(reverse=True)
    m = int(sqrt(N))
    while N % m !=0:
        m += 1
    n = N // m
    if m < n:
        t = m
        m = n
        n = t
    i=1
    j=1
    now = 0
    U = 1
    D = m
    L = 1
    R = n
    matrix = [[0 for j in range(110)] for i in range(10010)]
    while now < N:
        while now < N and j < R:
            matrix[i][j] = arr[now]
            now += 1
            j+=1
        while now < N and i < D:
            matrix[i][j] = arr[now]
            now += 1
            i+=1
        while now < N and j>L:
            matrix[i][j] = arr[now]
            now += 1
            j -= 1
        while now < N and i > U:
            matrix[i][j] = arr[now]
            now += 1
            i -= 1
        U += 1
        D -= 1
        L += 1
        R -= 1
        i += 1
        j += 1
        if now == N-1:
            matrix[i][j] = arr[now]
            now += 1
    for i in range(1,m+1):
        for j in range(1,n+1):
            print(matrix[i][j],end='')
            if j != n:
                print(' ',end='')
            else:
                print()
