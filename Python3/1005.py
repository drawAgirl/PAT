num = ["zero","one","two","three","four","five","six","seven","eight","nine"]
cnt = 0
n = input()
if n == '0':
    print("zero")
else:
    for _ in n:
        cnt = cnt + ord(_)-ord('0')
    ans = []
    while cnt != 0:
        ans.append(num[cnt%10])
        cnt = cnt // 10
    for i in range(len(ans)-1,-1,-1):
        print("%s"%ans[i],end='')
        if i != 0:
            print(" ",end='')