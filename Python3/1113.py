n = int(input())
num = list(map(int,input().split()))
num.sort()
a = sum(num[:len(num)//2])
b=sum(num[len(num)//2:])
if len(num) & 1:
    print("1 %d"%abs(a-b))
else:
    print("0 %d"%abs(a-b))
