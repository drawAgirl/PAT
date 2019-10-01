dic = {i:0 for i in range(10)}
n = input()
ans = []
temp=0
for each in reversed(n):
    dic[int(each)] += 1
    cur = int(each)*2+temp
    temp = cur//10
    dic[cur%10] -= 1
    ans.append(cur%10)
if temp != 0:
    ans.append(temp)
if len(ans) != len(n):
    print("No")
else:
    flag = True
    for i,j in dic.items():
        if j != 0:
            flag = False
            break
    if flag:
        print("Yes")
    else:
        print("No")
for each in ans[::-1]:
    print("%d"%each,end='')