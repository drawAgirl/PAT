n=int(input())
for _ in range(n):
    num = input()
    a = int(num[:len(num)//2])
    b = int(num[len(num)//2:])
    if a*b != 0 and int(num) %(a*b) == 0:
        print("Yes")
    else:
        print("No")