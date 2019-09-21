arr = [0,0,0,0]
def to_int(arr):
    ans = 0
    for i in range(4):
        ans = ans*10 + arr[i]
    return ans
def to_arr(n):
    for i in range(0,4):
        arr[i] = n % 10
        n = n//10

if __name__ == '__main__':
    n = int(input())
    while(1):
        to_arr(n)
        arr.sort()
        a = to_int(arr)
        arr.sort(reverse=True)
        b = to_int(arr)
        n = b - a
        print("%04d - %04d = %04d"%(b,a,n))
        if n == 6174 or n == 0:
            break